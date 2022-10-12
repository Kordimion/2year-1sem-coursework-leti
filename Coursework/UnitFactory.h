#pragma once
#include "Unit.h"
#include "Player.h"
class UnitFactory {
public:
	virtual Unit* create(Player p, Position f) = 0;
};