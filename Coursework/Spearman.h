#pragma once
#include "Warrior.h"
struct Spearman : public Warrior {
	Spearman(const Player* player, const Position& position) : Warrior(player, position) {}
	char display() override { return 'S'; };
};
