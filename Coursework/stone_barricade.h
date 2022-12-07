#pragma once
#include "field_object.h"

class StoneBarricade : public FieldObject {
public:
	char displayCharacter() const override { return 'S'; }
	const std::string fieldObjectName() const override { return "Stone Barricade"; }
	StoneBarricade(const Position& pos) : FieldObject(pos) {};
};