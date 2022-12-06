#pragma once
#include "Position.h"

struct FieldObject {
	virtual char displayCharacter() const = 0;
	virtual int displayColor() { return 35; };
	FieldObject(const Position& _pos) : pos(_pos) {}
	Position pos;
};