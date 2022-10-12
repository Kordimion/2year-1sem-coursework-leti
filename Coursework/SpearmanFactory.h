#pragma once
#include "UnitFactory.h"
#include "Spearman.h"

class SpearmanFactory :public UnitFactory {
public:
	Spearman* create(Player p, Position f) override {
		Spearman* s = new Spearman();
		s->pos.x = f.x;
		s->pos.y = f.y;
		s->playerId = p.id;
	}


};
