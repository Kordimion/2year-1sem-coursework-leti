#pragma once
#include "Warrior.h"
struct Swordsman : public Warrior {
	Swordsman(const Player* player, const Position& position) : Warrior(player, position) {}
	char display() override { return 'W'; };
};