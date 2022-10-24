#pragma once
#include "UnitFactory.h"
#include "Swordsman.h"

class SwordsmanFactory :public UnitFactory {
public:
	SwordsmanFactory() = default;
	Unit* create(const Player* player, const Position& pos) override
	{
		return new Swordsman(player, pos);
	}
	
};

