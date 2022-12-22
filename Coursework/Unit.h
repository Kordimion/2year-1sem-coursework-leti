#pragma once

#include "position.h"
#include "player.h"

/**
*@brief General characteristics of units
*/
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

	UnitStats(UnitStats* s) :
		startingHealth(s->startingHealth),
		range(s->range),
		damage(s->damage),
		armor(s->armor),
		speed(s->speed),
		health(s->health)
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

	void setHealth(double hl) { health = hl; }
private:
	double startingHealth; //<health at the time of creation
	int range; //<distance of attack
	double damage; //<damage to other units
	double armor; //protection from others
	double speed; //range of movement
	double health; //current health
};

/**
*@brief Parent of all unit types
*/
class Unit {
public:
	Position pos;
	const Player* player;

	Unit(const Player* _player, const Position& position){
		player = _player;
		pos = position;
	}

	Unit(const Unit* unit) : player(unit->player), pos(unit->pos), _stats(UnitStats(*unit->getStats())) {}

	const UnitStats* getStats() const {
		const UnitStats* stat = &_stats;
		return stat;
	}

	void setStats(const UnitStats& stats) {
		_stats = stats;
	}

	virtual char display() {
		return 'U';
	};

	virtual const char* toString() const {
		return "Unit";
	};
protected:
	UnitStats _stats; //<unit characteristics
};