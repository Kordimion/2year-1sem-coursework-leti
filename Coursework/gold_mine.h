#pragma once
#include "field_object.h"
#include "miner.h"

class GoldMine : public FieldObject {
public:
	char displayCharacter() const override { return 'M'; }
	const std::string fieldObjectName() const override { return "Gold Mine"; }
	GoldMine(const Position& pos) : FieldObject(pos) {};
	const bool isWalkable() const override { return true; };

	const std::string selectionMessage() const override {
		std::string res;

		if (_miner != nullptr) {
			res += "\nGold mine is occupied by ";
			res += _miner->toString();
		}
		else {
			res += "\nGold mine is not occupied";
		}

		return res;
	};

	const bool isInteractable() const override { return true; };
	const bool interactionAction(std::any payload) const override {
		auto unit = std::any_cast<Unit*>(payload);
		auto miner = dynamic_cast<Miner*>(unit);
		if(miner) DISPATCH(new NotImplementedErrorAction("You can't interact with gold mines yet"));
		else DISPATCH(new IncorrectInputErrorAction(std::string(unit->toString()) + " can't interact with gold mines"));
		return true;
	};

private:
	Miner* _miner;
};