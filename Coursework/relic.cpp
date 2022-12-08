#pragma once
#include "field_object.h"
#include "action_types.h"
#include "flux_cpp.h"
#include "relic.h"

const std::string const Relic::selectionMessage() const {
	std::string res;

	if (_holder != nullptr) {
		res += "\nRelic is held by unit ";
		res += _holder->toString();
	}
	else {
		res += "\nRelic is held by no one";
	}

	return res;
}

const std::string Relic::interactionMessage(std::any payload) const {
	std::string res;

	auto p = std::any_cast<Unit*>(payload);

	if (_holder == p) res = "\nPress '1' to drop the relic";
	else if (_holder == nullptr && p->pos == pos) res = "\nPress '1' to take the relic";
	else res = "";

	return res;
}

const bool Relic::interactionAction(std::any payload) const {
	auto p = std::any_cast<std::pair<Unit*, char>>(payload);
	auto unit = p.first;
	auto key = p.second;
	
	if (key == '1') {
		if (_holder == unit)
			DISPATCH(new DropRelicAction(const_cast<Relic*>(this)));
		else if (_holder == nullptr && unit->pos == pos) 
			DISPATCH(new SetRelicHolderAction(SetRelicHolderPayload(this, unit)));
		else return false;
	}
	return true;
};
