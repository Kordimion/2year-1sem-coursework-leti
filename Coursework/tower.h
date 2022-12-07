#pragma once
#include "field_object.h"

class Tower : public FieldObject {
public:
	char displayCharacter() const override { return 'T'; }
	const std::string fieldObjectName() const override { return "Tower"; }
	Tower(const Position& pos) : FieldObject(pos) {};
};