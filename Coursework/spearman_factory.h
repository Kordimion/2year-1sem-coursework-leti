#pragma once

#include "unit_factory.h"
#include "spearman.h"

class SpearmanFactory: public UnitFactory {
public:
	SpearmanFactory() = default;

	Unit* create(const Player* player, const Position& pos) override {
		return new Spearman(player, pos);
	}

	const char* toString() const override { 
		return "SpearmanFactory"; 
	}
};
