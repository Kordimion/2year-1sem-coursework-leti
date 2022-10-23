#pragma once

#include "UnitFactory.h"
#include "Miner.h"

class MinerFactory :public UnitFactory {
public:
	 Miner* create(const Player& player, const Position& pos, Miner* m)
	 {
		m->pos.x = pos.x;
		m->pos.y = pos.y;
		m->playerId = player.id;
		return m;
	 }

};
