#pragma once
#include "tower.h"
#include "unit_factory.h"
#include "farmer_factory.h"

/**
 * @brief Base for unit creation
 *
 * Also has the properties of a tower
 */
class Base : public Tower {
public:
	char displayCharacter() const override  { return 'B'; }
	const std::string fieldObjectName() const override { return "Base"; }
	Base(const Position& pos) : Tower(pos, 15) {};
	const bool isWalkable() const override { return true; }
	Player* player;
	UnitFactory* factory = new FarmerFactory();

	const std::string selectionMessage() const override;
	const bool selectionAction(std::any payload) const override;
};