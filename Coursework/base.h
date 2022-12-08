#pragma once
#include "tower.h"
#

class Base : public Tower {
public:
	char displayCharacter() const override  { return 'B'; }
	const std::string fieldObjectName() const override { return "Base"; }
	Base(const Position& pos) : Tower(pos, 15) {};
	const bool isWalkable() const override { return true; }
};