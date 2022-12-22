#pragma once

#include "unit.h"

/**
 * @brief Parent for all factories
 *
 * Class that regulates the creation of units
 */
class UnitFactory {
public:
	UnitFactory() = default;

	/**
	 * @brief Creation of unit
	 *
	 * @param player current player
	 * @param pos position for unit
	 * @return *unit
	 */
	virtual Unit* create(const Player* player, const Position& pos) { 
		return nullptr; 
	};

	virtual const char* toString() const { 
		return "UnitFactory"; 
	}

	virtual const int unitCost() const = 0;
};