#pragma once
#include "Worker.h"
struct Miner : public Worker {
	Miner(const Player* player, const Position& position) : Worker(player, position) {}
	char display() override { return 'M'; };
};
