#pragma once

#include <Windows.h>

#include "error_store.h"
#include "action_types.h"
#include "game.h"

void ErrorStore::process(const std::shared_ptr<flux_cpp::Action>& action) {
	auto actionType = action->getType<ErrorActionTypes>();

	switch (actionType){
	case ErrorActionTypes::ErrorResolved:
		hasError_ = false;
		break;

	case ErrorActionTypes::NotImplementedError:
		hasError_ = true;
		message = std::string("Not Implemented: ") + action->getPayload<std::string>();
		break;

	case ErrorActionTypes::IncorrectInputError:
		hasError_ = true;
		message = std::string("Incorrect Input: ") + action->getPayload<std::string>();
		break;
	}
}
