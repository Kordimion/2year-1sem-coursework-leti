#pragma once
#include "field_object.h"

/**
 * @brief Solid obstacle
 *
 * Has health
 * Can be destroyed
 */
class StoneBarricade : public FieldObject {
public:
	char displayCharacter() const override { return 'S'; }
	const std::string fieldObjectName() const override { return "Stone Barricade"; }
	StoneBarricade(const Position& pos) : FieldObject(pos) {};
	const int getHealth() const { return _health; }
	void dealDamage(int damage) { _health -= damage; }
	const std::string selectionMessage() const override {
		std::string res;
		res += "\n" + fieldObjectName() + " health points: " + std::to_string(_startingHealth) + "/" + std::to_string(_health);
		return res;
	}
protected:
	int _health = 20; //<curent strength
	const int _startingHealth = 20; //<starting strength
};