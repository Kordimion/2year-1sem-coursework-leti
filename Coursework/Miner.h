#pragma once
#include "Worker.h"

class MinerStats : public UnitStats {
public:
	MinerStats() :UnitStats(12, 1, 2, 2, 1) {}
};

class Miner : public Worker {
public:
	Miner(const Player* player, const Position& position) : Worker(player, position) 
	{
		_stats = MinerStats();
	}
	char display() override { return 'M'; };
};
