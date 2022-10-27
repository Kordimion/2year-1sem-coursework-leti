#pragma once
#include "Ranger.h"
#include "ArcherStats.h"
struct Archer : public Ranger {
	Archer(const Player* player, const Position& position) : Ranger(player,position) 
	{
		ArcherStats();
	}
	char display() override { return 'A'; };
};
