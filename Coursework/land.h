#pragma once
#include "unit.h"

class Land {
public:
	const virtual int displayColor() const = 0;
	const virtual char displayCharacter() const = 0;
	const virtual bool isWalkable() const = 0;
	const virtual int croplandProcessingTime() const { return -1; }
	const bool isCroplandProcessable() const { croplandProcessingTime() >= 0; };
	const virtual Unit* affectUnit(const Unit const* unit) const { return unit; }
};