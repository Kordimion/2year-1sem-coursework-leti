#pragma once
#include "land.h"
#include "unit.h"

class Forest : public Land {
public:
	const int displayColor() const override { return 32; };
	const char displayCharacter() const override{ return '^'; };
	const bool isWalkable() const override { return true; };
	const int croplandProcessingTime() const override { return 4; };
};