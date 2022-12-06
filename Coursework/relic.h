#pragma once
#include "field_object.h"

class Relic : public FieldObject {
public:
	char displayCharacter() const override { return 'R'; }
	Relic(const Position& pos) : FieldObject(pos) {};
};