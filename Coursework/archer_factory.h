#pragma once

#include "unit_factory.h"
#include "archer.h"

class ArcherFactory: public UnitFactory {
public:
	ArcherFactory() = default;

	Unit* create(const Player* player, const Position& pos) override {
		return new Archer(player, pos);
	}

	const char* toString() const override { 
		return "ArcherFactory"; 
	}
};