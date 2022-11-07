#pragma once

#include "position.h"
#include "player.h"


class UnitStats {
public:
	UnitStats() = default;

	UnitStats(double sH, int rg, double dm, double ar, double sp) :
		startingHealth(sH),
		range(rg),
		damage(dm),
		armor(ar),
		speed(sp),
		health(sH)
	{}

	double getStartingHealth() const {
		return startingHealth;
	}

	double getRange() const {
		return range;
	}

	double getDamage() const{
		return damage;
	}

	double getArmor() const {
		return armor;
	}

	double getSpeed() const {
		return speed;
	}

	double getHealth() const {
		return health;
	}

	double setHealth(double hl) {}
private:
	double startingHealth;
	int range;
	double damage;
	double armor;
	double speed;
	double health;
};

class Unit {
public:
	Position pos;
	const Player* player;

	Unit(const Player* _player, const Position& position){
		player = _player;
		pos = position;
	}

	const UnitStats* getStats() const {
		const UnitStats* stat = &_stats;
		return stat;
	}

	virtual char display() = 0;

	virtual const char* toString() const { 
		return "Unit"; 
	}
protected:
	UnitStats _stats;
};