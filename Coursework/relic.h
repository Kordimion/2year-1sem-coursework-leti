#pragma once
#include "field_object.h"

class Relic : public FieldObject {
public:
	char displayCharacter() const override { return 'R'; }
	const std::string fieldObjectName() const override { return "Relic"; }
	Relic(const Position& pos) : FieldObject(pos) {};

	const bool isWalkable() const override { return true; }

	const std::string selectionMessage() const override {
		std::string res;

		if (_holder != nullptr) {
			res += "\nRelic is held by unit ";
			res += _holder->toString();
		}
		else {
			res += "\nRelic is held by noone";
		}

		return res;
	}

	const bool isInteractable() const override { return true; };
	const bool interactionAction(std::any payload) const override {
		DISPATCH(new NotImplementedErrorAction("You can't interact with relics yet"));
		return true;
	};

private:
	Unit* _holder;
};