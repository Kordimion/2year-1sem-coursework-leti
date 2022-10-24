#pragma once
#include "UnitFactory.h"
#include "Slinger.h"

class SlingerFactory :public UnitFactory {
public:
	SlingerFactory() = default;
	Unit* create(const Player* player,const Position& pos) override
	{
		return new Slinger(player, pos);
	}
	const char* toString() const  override { return "SlingerFactory"; }
};