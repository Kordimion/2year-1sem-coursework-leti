#pragma once
#include "land.h"
#include "unit.h"

/**
* @brief Land that affects the unit's movement
*/
class Water : public Land {
public:
	const int displayColor() const override { return 34; };
	const char displayCharacter() const override { return '~'; };
	const bool isWalkable() const override { return false; };
};