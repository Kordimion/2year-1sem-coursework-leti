#pragma once
#include "UnitFactory.h"
#include "Slinger.h"

class SlingerFactory :public UnitFactory {
public:
	Slinger* create(Player p, Position f) override {
		Slinger* l = new Slinger();
		l->pos.x = f.x;
		l->pos.y = f.y;
		l->playerId = p.id;
	}


};