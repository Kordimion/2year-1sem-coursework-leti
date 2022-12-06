#pragma once
#include "field_object.h"

class Tower : public FieldObject {
public:
	char displayCharacter() const override { return 'T'; }
	Tower(const Position& pos) : FieldObject(pos) {};
};