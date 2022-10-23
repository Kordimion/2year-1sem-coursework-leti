#pragma once
#include "UnitFactory.h"
#include "Swordsman.h"

class SwordsmanFactory :public UnitFactory {
public:
	Swordsman* create(const Player& player, const Position& pos, Swordsman* w) 
	{
		w->pos.x = pos.x;
		w->pos.y = pos.y;
		w->playerId = player.id;
		return w;
	}


};

