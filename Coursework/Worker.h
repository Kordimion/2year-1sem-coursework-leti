#pragma once

#include "unit.h"

class Worker : public Unit {
public:
	Worker(const Player* player, const Position& position) : Unit(player, position) {}
	
	virtual char display() = 0;
};
