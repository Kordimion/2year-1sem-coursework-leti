#pragma once
#include "field_object.h"

class Relic : public FieldObject {
public:
	char displayCharacter() const override { return 'R'; }
	const std::string fieldObjectName() const override { return "Relic"; }
	Relic(const Position& pos) : FieldObject(pos) {};
};