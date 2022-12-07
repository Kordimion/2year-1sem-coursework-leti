#pragma once
#include "field_object.h"

class Base : public FieldObject {
public:
	char displayCharacter() const override  { return 'B'; }
	const std::string fieldObjectName() const override { return "Base"; }
	Base(const Position& pos) : FieldObject(pos) {};

};