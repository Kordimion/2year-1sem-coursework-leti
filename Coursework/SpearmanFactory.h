#pragma once
#include "UnitFactory.h"
#include "Spearman.h"

class SpearmanFactory :public UnitFactory {
public:
	Spearman* create(const Player& player, const Position& pos, Spearman* s) 
	{
		s->pos.x = pos.x;
		s->pos.y = pos.y;
		s->playerId = player.id;
		return s;
	}

};
