#pragma once

#include "warrior.h"

class SpearmanStats : public UnitStats {
public:
	SpearmanStats() :UnitStats(25, 2, 8, 4, 2) {}
};

/**
* Armor piercing
*/
class Spearman : public Warrior {
public:
	Spearman(const Player* player, const Position& position) : Warrior(player, position) {
		_stats = SpearmanStats();
	}

	char display() override { 
		return 'S'; 
	}

	const char* toString() const override {
		return "Spearman";
	}
};
