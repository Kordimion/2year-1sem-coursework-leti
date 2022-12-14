#pragma once

#include "worker.h"

class MinerStats : public UnitStats {
public:
	MinerStats() :UnitStats(12, 1, 2, 2, 1) {}
};

/**
 * Can occupy gold mines
 */
class Miner : public Worker {
public:
	Miner(const Player* player, const Position& position) : Worker(player, position) {
		_stats = MinerStats();
	}

	char display() override { 
		return 'M'; 
	}

	const char* toString() const override { 
		return "Miner"; 
	}
};
