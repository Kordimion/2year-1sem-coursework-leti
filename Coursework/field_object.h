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
	virtual const bool isSelectable() const { return false; };
	virtual const std::string selectionMessage() const { return ""; };
	virtual const std::string interactionMessage() const { return ""; };
	virtual const void selectionAction(std::any payload) const {};
	virtual const void interactionAction(std::any payload) const {};
	Position pos;
};

struct SelectableFieldObject : public FieldObject {
	virtual std::string selectionInfo() = 0;
	virtual std::string fieldObjectAction(std::any payload) = 0;
};

struct WalkableFieldObject : public SelectableFieldObject {
	
};

struct InteractableFieldObject : public FieldObject {

};