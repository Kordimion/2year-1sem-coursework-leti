#pragma once

#include <iostream>
#include <Windows.h>
#include <fstream>
#include "flux_cpp.h"
#include "game.h"
#include "action_types.h"
#include "unit_type.h"
#include <string>
#include "Position.h"

//TODO !fix pointers!

class Logger {
public:
	Logger() = default;
	virtual void log(std::string message) {}
};

//TODO rename(adapter)  
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
		//TODO into errors
		if (!_out.is_open()) {
			std::cout << "\n\nFileProblem";
		}
		_out << message << "\n";
		_out.close();
		_logger->log(message);
	}
private:
	std::ofstream _out;
	Logger* _logger;
};

class LoggerConsoleProxy : public Logger {
public:
	LoggerConsoleProxy(Logger* logger) : _logger(logger) {};
	void log(std::string message) override {
		std::cout << "\n\n\n" << message;
		Logger::log(message);
	}
private:
	Logger* _logger;
};


class LoggerFormatAdapter {
public:
	LoggerFormatAdapter() = default;
	virtual std::string format(const std::shared_ptr<flux_cpp::Action>& action) { return ""; };
};

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

class DescriptiveLoggerFormatAdapter : public LoggerFormatAdapter {
	std::string format(const std::shared_ptr<flux_cpp::Action>& action) override {
		return " ";
	}
};

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

