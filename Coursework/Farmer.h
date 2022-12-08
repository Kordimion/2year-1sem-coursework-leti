#pragma once

#include "worker.h"

class FarmerStats : public UnitStats {
public:
	FarmerStats() :UnitStats(15, 1, 3, 1, 1) {}
};

/**
* Gives food to the city by growing crops on farms
* Can build farms himself on grass
*/
class Farmer : public Worker {
public:
	Farmer(const Player* player, const Position& position) :Worker(player, position) {
		_stats=FarmerStats();
	}

	char display() override { 
		return 'F'; 
	}

	const char* toString() const override {
		return "Farmer";
	}
};