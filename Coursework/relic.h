#pragma once
#include "field_object.h"

/**
 * @brief Special bonus
 *
 * Unit can hold it
 * The goal is to bring to the base
 */
class Relic : public FieldObject {
public:
	char displayCharacter() const override { return 'R'; }
	const std::string fieldObjectName() const override { return "Relic"; }
	Relic(const Position& pos) : FieldObject(pos) {};

	const bool isWalkable() const override { return true; }

	const std::string selectionMessage() const override;

	const Unit* getHolder() { return _holder; };

	void setHolder(Unit* holder) { _holder = holder; };

	const bool isInteractable() const override { return true; };

	const std::string interactionMessage(std::any payload) const override;

	const bool interactionAction(std::any payload) const override;

private:
	Unit* _holder; //<personality of the interacting
};