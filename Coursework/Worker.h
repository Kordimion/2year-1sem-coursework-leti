#pragma once
#include "Unit.h"
struct Worker : public Unit {
	Worker(const Player* player, const Position& position) : Unit(player, position) {}
	virtual char display() = 0;
};
