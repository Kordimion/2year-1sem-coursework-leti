#pragma once
#include "Ranger.h"
struct Slinger : public Ranger {
	Slinger(const Player* player, const Position& position) : Ranger(player, position) {}
	char display() override { return 'L'; };
};
