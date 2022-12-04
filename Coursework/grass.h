#pragma once
#include "land.h"
#include "unit.h"

class Grass : public Land {
public:
	const virtual int displayColor() const override { return 32; };
	const virtual char displayCharacter() const override { return '*'; };
	const virtual bool isWalkable() const override { return true; };
	const int croplandProcessingTime() const override { return 2; };
};