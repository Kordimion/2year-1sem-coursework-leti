#pragma once
#include "Unit.h"
#include "UnitType.h"


class UnitFactory {
public:
	UnitFactory() = default;
	virtual Unit* create(const Player* player, const Position& pos) { return  nullptr; };
	virtual const char* toString() const { return "UnitFactory"; }

};