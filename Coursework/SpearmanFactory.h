#pragma once
#include "UnitFactory.h"
#include "Spearman.h"

class SpearmanFactory :public UnitFactory {
public:
	SpearmanFactory() = default;
	Unit* create(const Player* player, const Position& pos) override
	{
		return new Spearman(player, pos);
	
	}

};
