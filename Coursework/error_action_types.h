#pragma once

#include "serializable_action.h"

enum class ErrorActionTypes {
	ErrorResolved = 10,
	NotImplementedError,
	IncorrectInputError
};

struct ErrorResolvedAction : public SerializableAction {
	ErrorResolvedAction() : SerializableAction(ErrorActionTypes::ErrorResolved) {}
};

struct NotImplementedErrorAction : public SerializableAction {
	NotImplementedErrorAction(std::string payload) : SerializableAction(ErrorActionTypes::NotImplementedError, payload) {}
};

struct IncorrectInputErrorAction : public SerializableAction {
	IncorrectInputErrorAction(std::string payload) : SerializableAction(ErrorActionTypes::IncorrectInputError, payload) {}
};