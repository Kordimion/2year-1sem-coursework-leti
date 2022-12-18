#pragma once
#include "field_object.h"
#include <vector>
#include "Unit.h"

class Tower : public FieldObject {
public:
	char displayCharacter() const override { return 'T'; }
	const std::string fieldObjectName() const override { return "Tower"; }
	Tower(const Position& pos, int health = 10) : FieldObject(pos), _health(health), _startingHealth(health) {};
	const bool isWalkable() const override { return true; }
	const int getHealth() const { return _health; }
	void dealDamage(int damage) { _health -= damage; }
	const std::string selectionMessage() const override;
	const bool isInteractable() const override { return true; };
	const std::string interactionMessage(std::any payload) const override;
	const bool interactionAction(std::any payload) const override;

	const std::vector<Unit*>& getEnteredUnits() const { return _enteredUnits; };
	void addNewUnit(Unit* unit) { _enteredUnits.push_back(unit); }
	void popEnteredUnit(Unit* unit) {
		auto it = std::find(_enteredUnits.begin(), _enteredUnits.end(), unit);
		if (it != std::end(_enteredUnits)) _enteredUnits.erase(it);
	}
protected:
	int _health;
	const int _startingHealth;
	std::vector<Unit*> _enteredUnits;
};