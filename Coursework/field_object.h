#pragma once
#include "Position.h"
#include <string>
#include <any>

struct FieldObject {
	virtual char displayCharacter() const = 0;
	virtual int displayColor() { return 35; };
	FieldObject(const Position& _pos) : pos(_pos) {}
	virtual const std::string fieldObjectName() const = 0;
	virtual const bool isWalkable() const { return false; };
	virtual const bool isInteractable() const { return false; };
	virtual const std::string selectionMessage() const { return "\nundefined"; };
	virtual const std::string interactionMessage() const { return "\nundefined"; };
	// returns true if it handled input
	virtual const bool selectionAction(std::any payload) const { return false; };
	// returns true if it handled input
	virtual const bool interactionAction(std::any payload) const { return false; };
	Position pos;
};