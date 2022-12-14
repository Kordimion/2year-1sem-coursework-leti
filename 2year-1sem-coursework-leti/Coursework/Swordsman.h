#pragma once

#include "warrior.h"

class SwordsmanStats : public UnitStats {
public:
	SwordsmanStats() :UnitStats(25, 1, 7, 4, 2) {}
};

/**
* Do splash damage
*/
class Swordsman : public Warrior {
public:
	Swordsman(const Player* player, const Position& position) : Warrior(player, position) {
		_stats = SwordsmanStats();
	}

	char display() override {
		return 'W'; 
	}

	const char* toString() const override {
		return "Swordsman";
	}
};