#pragma once

#include "UnitFactory.h"
#include "Archer.h"

class ArcherFactory:public UnitFactory {
public:
	Archer* create(Player p, Position f) override {
		Archer* b = new Archer();
		b->pos.x = f.x;
		b->pos.y = f.y;
		b->playerId = p.id;
	}
		
};