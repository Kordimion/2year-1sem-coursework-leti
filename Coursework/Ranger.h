#pragma once

#include "unit.h"
/**
* Long range fighter
* Has low damage
*/
class Ranger : public Unit {
public:
	Ranger(const Player* player, const Position& position) : Unit(player, position) {}
	
	virtual char display() = 0;
};
