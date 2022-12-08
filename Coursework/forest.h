#pragma once
#include "land.h"
#include "unit.h"
#include <algorithm>

class Forest : public Land {
public:
	const int displayColor() const override { return 32; };
	const char displayCharacter() const override{ return '^'; };
	const bool isWalkable() const override { return true; };

	const virtual Unit affectUnit(const Unit const* _unit) const { 
		Unit unit(_unit);
		auto stats = unit.getStats();
		auto newStats = UnitStats(
			stats->getStartingHealth(),
			std::min(stats->getRange(), 2.0),
			stats->getDamage(),
			stats->getArmor(),
			stats->getSpeed()
		);

		newStats.setHealth(stats->getHealth());
		unit.setStats(newStats);
		return unit;
	}
};