#pragma once
#include "Worker.h"
struct Farmer : public Worker {
	Farmer(const Player* player, const Position& position) :Worker(player, position) {}
	char display() override { return 'F'; };
};