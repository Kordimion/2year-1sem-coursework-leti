#pragma once
#include "field_object.h"

class Base : public FieldObject {
public:
	char displayCharacter() const override  { return 'B'; }
	Base(const Position& pos) : FieldObject(pos) {};
};