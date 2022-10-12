#pragma once

#include "UnitFactory.h"
#include "Miner.h"

class MinerFactory :public UnitFactory {
public:
	 Miner* create(Player p, Position f) override {
		Miner* m = new Miner();
		m->pos.x = f.x;
		m->pos.y = f.y;
		m->playerId = p.id;
	}

};
