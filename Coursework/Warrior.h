#pragma once
#include "Unit.h"
struct Warrior : public Unit {
	Warrior(const Player* player, const Position& position) : Unit(player, position) {}
	virtual char display() = 0;
};
