#pragma once

#include "UnitFactory.h"
#include "Farmer.h"

class FarmerFactory :public UnitFactory {
public:
	FarmerFactory() = default;
	Unit* create(const Player* player ,const  Position& pos) override
	{
		return new Farmer(player, pos);
	}
	const char* toString() const override { return "FarmerFactory"; }

};

