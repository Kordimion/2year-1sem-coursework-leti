#pragma once

#include "unit.h"

/**
* Neffective for combat
* Can do extra stuff
*/
class Worker : public Unit {
public:
	Worker(const Player* player, const Position& position) : Unit(player, position) {}
	
	virtual char display() = 0;
};
