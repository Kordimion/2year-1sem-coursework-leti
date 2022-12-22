#pragma once

#include "serializable_action.h"

enum class ErrorActionTypes {
	ErrorResolved = 10,
	NotImplementedError,
	IncorrectInputError
};

struct ErrorResolvedAction : public SerializableAction {
	ErrorResolvedAction() : SerializableAction(ErrorActionTypes::ErrorResolved) {}

	const std::string Serialize() const override { return "ErrorResolvedAction|"; };
};

struct NotImplementedErrorAction : public SerializableAction {
	NotImplementedErrorAction(std::string payload) : SerializableAction(ErrorActionTypes::NotImplementedError, payload) {}

	const std::string Serialize() const override { return std::string("NotImplementedErrorAction|") + getPayload<std::string>(); };
};

struct IncorrectInputErrorAction : public SerializableAction {
	IncorrectInputErrorAction(std::string payload) : SerializableAction(ErrorActionTypes::IncorrectInputError, payload) {}

	const std::string Serialize() const override { return std::string("IncorrectInputErrorAction|") + getPayload<std::string>(); };
};