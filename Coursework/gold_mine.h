#pragma once
#include "field_object.h"

class GoldMine : public FieldObject {
public:
	char displayCharacter() const override { return 'M'; }
	const std::string fieldObjectName() const override { return "Gold Mine"; }
	GoldMine(const Position& pos) : FieldObject(pos) {};
};