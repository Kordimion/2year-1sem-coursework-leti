#pragma once
#include "UnitFactory.h"
#include "Swordsman.h"

class SwordsmanFactory :public UnitFactory {
public:
	Swordsman* create(Player p, Position f) override {
		Swordsman* w = new Swordsman();
		w->pos.x = f.x;
		w->pos.y = f.y;
		w->playerId = p.id;
	}


};

