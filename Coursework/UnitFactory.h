#pragma once
#include "Unit.h"
#include "UnitType.h"


class UnitFactory {
public:
	virtual Unit* create(const Player& player, const Position& pos, Unit* unit) = 0;
	void deleting(Unit* unit) 
	{
		delete unit;
	}
};