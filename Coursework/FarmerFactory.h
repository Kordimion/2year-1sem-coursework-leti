#pragma once

#include "UnitFactory.h"
#include "Farmer.h"

class FarmerFactory :public UnitFactory {
public:
	Farmer* create(const Player& player ,const  Position& pos, Farmer* fr) 
	{
		fr->pos.x = pos.x;
		fr->pos.y = pos.y;
		fr->playerId = player.id;
		return fr;
	}

};

