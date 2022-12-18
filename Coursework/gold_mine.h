#pragma once
#include "field_object.h"

class GoldMine : public FieldObject {
public:
	char displayCharacter() const override { return 'M'; }
	GoldMine(const Position& pos) : FieldObject(pos) {};
};