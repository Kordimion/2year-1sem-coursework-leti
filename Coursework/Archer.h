#pragma once
#include "ranger.h"

class ArcherStats : public UnitStats {
public:
	ArcherStats(): UnitStats(15, 5, 6, 2, 2) {}
};

class Archer: public Ranger {
public:
	Archer(const Player* player, const Position& position) : Ranger(player, position) {
		_stats = ArcherStats();
	}

	char display() override { 
		return 'A'; 
	};

	const char* toString() const override { 
		return "Archer"; 
	}
};
