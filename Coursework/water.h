#pragma once
#include "land.h"
#include "unit.h"

class Water : public Land {
public:
	const int displayColor() const override { return 34; };
	const char displayCharacter() const override { return '~'; };
	const bool isWalkable() const override { return false; };
};