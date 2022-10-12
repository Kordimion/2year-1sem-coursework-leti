#pragma once

#include "UnitFactory.h"
#include "Farmer.h"

class FarmerFactory :public UnitFactory {
public:
	Farmer* create(Player p, Position f) override {
		Farmer* fr = new Farmer();
		fr->pos.x = f.x;
		fr->pos.y = f.y;
		fr->playerId = p.id;
	}

};