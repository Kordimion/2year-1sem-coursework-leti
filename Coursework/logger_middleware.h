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
	LoggerFileProxy() {
		out.open("log.txt", std::ios_base::trunc);
		if (!out.is_open()) {
			std::cout << "\n\nFileProblem";
		}
		out.close();
	}
	void log(std::string message) override{
		out.open("log.txt", std::ios_base::app);
		//TODO into errors
		if (!out.is_open()) {
			std::cout << "\n\nFileProblem";
		}
		out << message << "\n";
		out.close();
		Logger::log(message);
	}
private:
	std::ofstream out;
};

class LoggerConsoleProxy : public Logger {
public:
	LoggerConsoleProxy() = default;
	void log(std::string message) override{
		std::cout << "\n\n\n"<<message;
		Logger::log(message);
	}
};


class LoggerFormatAdapter {
public:
	LoggerFormatAdapter() = default;
	virtual std::string format(const std::shared_ptr<flux_cpp::Action>& action) { return ""; };
};

class ShortLoggerFormatAdapter : public LoggerFormatAdapter {
	std::string format(const std::shared_ptr<flux_cpp::Action>& action) override {
		std::string message;
		auto actionType = action->getType<UnitActionTypes>();

		switch (actionType) {
		case UnitActionTypes::SelectUnitCreationType:
			message.clear();
			message += "SelectUnitCreationType|";  
			message += std::to_string(int(action->getPayload<UnitType>()));
			break;
		case UnitActionTypes::AddUnit:
			message.clear();
			message += "AddUnit|";
			message += action->getPayload<Position>().Position::toString();
			break;
		case UnitActionTypes::SelectUnitStarted:
			message.clear();
			message += "SelectUnitStarted|";
			break;
		case UnitActionTypes::SelectUnitStopped:
			message.clear();
			message += "SelectUnitStopped|";
			break;
		case UnitActionTypes::SelectNextUnit:
			message.clear();
			message += "SelectNextUnit|";
			break;
		case UnitActionTypes::SelectPreviousUnit:
			message.clear();
			message += "SelectPreviousUnit|";
			break;
		case UnitActionTypes::DeleteSelectedUnit:
			message.clear();
			message += "DeleteSelectedUnit|";
			break;
		case UnitActionTypes::MoveUnitStarted:
			message.clear();
			message += "MoveUnitStarted|";
			break;
		case UnitActionTypes::MoveUnit:
			message.clear();
			message += "MoveUnit|";
			message += action->getPayload<Position>().Position::toString();
			break;
		case UnitActionTypes::MoveUnitCanceled:
			message.clear();
			message += "MoveUnitCanceled|";
			break;
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
	void operator<< (const std::shared_ptr<flux_cpp::Action>& action) {
		this->Log(action);
	}

	void Log(const std::shared_ptr<flux_cpp::Action>& action) {
		std::string log_entry = format_adapter->format(action);
		_logger->log (log_entry);
	}
private:
	Logger* _logger = new LoggerConsoleProxy;
	LoggerFormatAdapter* format_adapter = new LoggerFormatAdapter;
};

class LoggerMiddleware final : public flux_cpp::Middleware {
public:
	LoggerMiddleware() {
		logger = new ActionLogger(new ShortLoggerFormatAdapter, new LoggerFileProxy());
	}
	static LoggerMiddleware* instance() {
		static LoggerMiddleware* self = new LoggerMiddleware();
		return self;
	}
	std::shared_ptr<flux_cpp::Action> process(const std::shared_ptr<flux_cpp::Action>& action) override {
		//TODO <<
		//logger<<action;
		logger->Log(action);
		return action;
	}
private:
	ActionLogger* logger;
};









