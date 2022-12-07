#pragma once
#include "Position.h"
#include <string>
#include <any>

struct FieldObject {
	virtual char displayCharacter() const = 0;
	virtual int displayColor() { return 35; };
	FieldObject(const Position& _pos) : pos(_pos) {}
	virtual const std::string fieldObjectName() const = 0;
	Position pos;
};

struct SelectableFieldObject : public FieldObject {
	virtual std::string selectionInfo() = 0;
	virtual std::string fieldObjectAction(std::any payload) = 0;
};