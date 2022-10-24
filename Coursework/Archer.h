#pragma once
#include "Ranger.h"
struct Archer : public Ranger {
	Archer(const Player* player, const Position& position) : Ranger(player,position) {}
	char display() override { return 'A'; };
};
