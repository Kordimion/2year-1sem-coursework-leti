#pragma once

#include "unit_factory.h"
#include "swordsman.h"

class SwordsmanFactory: public UnitFactory {
public:
	SwordsmanFactory() = default;

	Unit* create(const Player* player, const Position& pos) override {
		return new Swordsman(player, pos);
	}

	const char* toString() const override { 
		return "SwordsmanFactory"; 
	}

	virtual const int unitCost() const override {
		return 30;
	};
};

