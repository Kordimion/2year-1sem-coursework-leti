#pragma once
#include "field_object.h"

class Tower : public FieldObject {
public:
	char displayCharacter() const override { return 'T'; }
	const std::string fieldObjectName() const override { return "Tower"; }
	Tower(const Position& pos, int health = 10) : FieldObject(pos), _health(health), _startingHealth(health) {};
	const bool isWalkable() const override { return true; }
	const int getHealth() const { return _health; }
	void dealDamage(int damage) { _health -= damage; }
	const std::string selectionMessage() const override {
		std::string res;
		res += "\n" + fieldObjectName() + " health points: " + std::to_string(_startingHealth) + "/" + std::to_string(_health);
		return res;
	}
	const bool isInteractable() const override { return true; };
	const bool interactionAction(std::any payload) const override {
		DISPATCH(new NotImplementedErrorAction("You can't interact with towers yet"));
		return true;
	};
protected:
	int _health;
	const int _startingHealth;
};