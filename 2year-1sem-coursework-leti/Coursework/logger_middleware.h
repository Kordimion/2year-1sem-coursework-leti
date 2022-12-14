#pragma once

#include <iostream>
#include <Windows.h>
#include <fstream>
#include "flux_cpp.h"
#include "game.h"
#include "action_types.h"
#include <string>
#include "Position.h"

/**
* @brief Parent for two directions of message
*
*/
class Logger {
public:
	Logger() = default;
	virtual void log(std::string message) {}
};

/**
* @brief Does logging to a file
*
*/
class LoggerFileProxy : public Logger {
public:
	LoggerFileProxy(Logger* logger) : _logger(logger) {
		_out.open("log.txt", std::ios_base::trunc);
		if (!_out.is_open()) {
			std::cout << "\n\nFileProblem";
		}
	}
	~LoggerFileProxy() {
		_out.close();
		delete _logger;
	}
	void log(std::string message) override {
		_out.open("log.txt", std::ios_base::app);
		if (!_out.is_open()) {
			std::cout << "\n\nFileProblem";
		}
		_out << message << "\n";
		_out.close();
		_logger->log(message);
	}
private:
	std::ofstream _out; //<stream for file
	Logger* _logger; //<object of parent class
};

/**
* @brief Does logging to the console
*
*/
class LoggerConsoleProxy : public Logger {
public:
	LoggerConsoleProxy(Logger* logger) : _logger(logger) {};
	void log(std::string message) override {
		std::cout << "\n\n\n" << message;
		Logger::log(message);
	}
private:
	Logger* _logger; //<object of parent class
};

/**
* @brief Parent for two forms of message
*
*/
class LoggerFormatAdapter {
public:
	LoggerFormatAdapter() = default;
	virtual std::string format(const std::shared_ptr<flux_cpp::Action>& action) { return ""; };
};

/**
* @brief Create short form of logging message
*
*/
class ShortLoggerFormatAdapter : public LoggerFormatAdapter {
	std::string format(const std::shared_ptr<flux_cpp::Action>& action) override {
		std::string message;
		try {
			SerializableAction* b = (SerializableAction*) (action.get());
			message = b->Serialize();
		}
		catch(std::exception e) {
			message = "unhandled action happened";
		}
		return message;
	}

};

/**
* @brief Create long form of logging message
*
*/
class DescriptiveLoggerFormatAdapter : public LoggerFormatAdapter {
	std::string format(const std::shared_ptr<flux_cpp::Action>& action) override {
		return " ";
	}
};

/**
* @brief Defines the form and direction of logging
*
*/
class ActionLogger {
public:
	ActionLogger(LoggerFormatAdapter* f_adapter, Logger* log) {
		delete format_adapter;
		format_adapter = f_adapter;
		delete _logger;
		_logger = log;
	}
	~ActionLogger() {}
	friend ActionLogger* operator<< (ActionLogger* logger, const std::shared_ptr<flux_cpp::Action>& action);
	/**
	* The main function for logging
	*/
	void Log(const std::shared_ptr<flux_cpp::Action>& action) {
		std::string log_entry = format_adapter->format(action);
		_logger->log(log_entry);
	}
private:
	Logger* _logger = new LoggerFileProxy(new Logger());
	LoggerFormatAdapter* format_adapter = new LoggerFormatAdapter;
};

ActionLogger* operator<< (ActionLogger* logger, const std::shared_ptr<flux_cpp::Action>& action) {
	logger->Log(action);
	return logger;
}

/**
* @brief Logging actions
*
*/
class LoggerMiddleware final : public flux_cpp::Middleware {
public:
	LoggerMiddleware() {
		logger = new ActionLogger(new ShortLoggerFormatAdapter, new LoggerFileProxy(new Logger()));
	}
	static LoggerMiddleware* instance() {
		static LoggerMiddleware* self = new LoggerMiddleware();
		return self;
	}
	std::shared_ptr<flux_cpp::Action> process(const std::shared_ptr<flux_cpp::Action>& action) override {
		logger << action;
		return action;
	}
private:
	ActionLogger* logger;
};

