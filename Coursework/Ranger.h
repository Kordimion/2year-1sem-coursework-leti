#pragma once
#include "Unit.h"
struct Ranger : public Unit {
	Ranger(const Player* player, const Position& position) : Unit(player, position) {}
	virtual char display() = 0;
};
