#pragma once
#include "Unit.h"

class Warrior : public Unit {
public:
	Warrior(const Player* player, const Position& position) : Unit(player, position) {}
	virtual char display() = 0;
};
