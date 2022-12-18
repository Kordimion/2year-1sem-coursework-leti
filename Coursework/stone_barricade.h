#pragma once
#include "field_object.h"

class StoneBarricade : public FieldObject {
public:
	char displayCharacter() const override { return 'K'; }
	StoneBarricade(const Position& pos) : FieldObject(pos) {};
};