#pragma once

#include "UnitFactory.h"
#include "Miner.h"

class MinerFactory :public UnitFactory {
public:
	MinerFactory() = default;
	 Unit* create(const Player* player, const Position& pos) override
	 {
		 return new Miner(player, pos);
	 }

};
