#pragma once

#include "UnitFactory.h"
#include "Archer.h"


class ArcherFactory:public UnitFactory {
public:
	Archer* create(const Player &player, const Position &pos, Archer* b) 
	{
		//Archer* b = new Archer(player,pos);
		b->pos.x = pos.x;
		b->pos.y = pos.y;
		b->playerId = player.id;
		return b;
	}

};