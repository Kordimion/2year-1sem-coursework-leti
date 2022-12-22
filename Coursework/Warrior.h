#pragma once

#include "unit.h"

/**
* Close range fighter
* Can wear heavy armor and shields
* High damage
*/
class Warrior : public Unit {
public:
	Warrior(const Player* player, const Position& position) : Unit(player, position) {}
	
	virtual char display() = 0;
};
