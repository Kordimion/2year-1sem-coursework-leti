#pragma once

#include "ranger.h"

class SlingerStats : public UnitStats {
public:
	SlingerStats() : UnitStats(12, 4, 4, 1, 2) {}
};

/**
* Low cost and 2-turn recharge
*/
class Slinger : public Ranger {
public:
	Slinger(const Player* player, const Position& position) : Ranger(player, position) {
		_stats = SlingerStats();
	}

	char display() override { 
		return 'L'; 
	}

	const char* toString() const override {
		return "Slinger";
	}

};
