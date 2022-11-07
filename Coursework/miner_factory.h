#pragma once

#include "unit_factory.h"
#include "miner.h"

class MinerFactory :public UnitFactory {
public:
	MinerFactory() = default;

	 Unit* create(const Player* player, const Position& pos) override {
		 return new Miner(player, pos);
	 }

	 const char* toString() const override { 
		 return "MinerFactory"; 
	 }
};
