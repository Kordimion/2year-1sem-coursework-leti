#pragma once
#include "Ranger.h"

class SlingerStats : public UnitStats {
public:
	SlingerStats() :UnitStats(12, 4, 4, 1, 2) {}
};

class Slinger : public Ranger {
public:
	Slinger(const Player* player, const Position& position) : Ranger(player, position) 
	{
		_stats = SlingerStats();
	}
	char display() override { return 'L'; };
};
