#pragma once
#include "UnitFactory.h"
#include "Slinger.h"

class SlingerFactory :public UnitFactory {
public:
	Slinger* create(const Player& player,const Position& pos, Slinger* l) 
	{
		l->pos.x = pos.x;
		l->pos.y = pos.y;
		l->playerId = player.id;
		return l;
	}

};