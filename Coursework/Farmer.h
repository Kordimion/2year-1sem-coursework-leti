#pragma once
#include "Worker.h"

class FarmerStats : public UnitStats {
public:
	FarmerStats() :UnitStats(15, 1, 3, 1, 1) {}
};

class Farmer : public Worker {
public:
	Farmer(const Player* player, const Position& position) :Worker(player, position) 
	{
		_stats=FarmerStats();
	}
	char display() override { return 'F'; };
};