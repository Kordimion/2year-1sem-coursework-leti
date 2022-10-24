#pragma once

#include "UnitFactory.h"
#include "Archer.h"


class ArcherFactory:public UnitFactory {
public:
	ArcherFactory() = default;
	Unit* create(const Player* player, const Position& pos) override
	{
		return new Archer(player, pos);
	}

};