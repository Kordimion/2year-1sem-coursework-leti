#pragma once

class UnitStats {
	double startingHealth;
	int range;
	int damage;
	double armor;
	double speed;
	double health;
protected:
	UnitStats(double sH, int rg,int dm, double ar,double sp)		
	{
		startingHealth = sH; 
		range = rg;
		damage = dm;
		armor = ar;
		speed = sp;
		health = startingHealth;
	}
	double getStartingHealth() const
	{
		return startingHealth;
	}
	double getRange() const
	{
		return range;
	}
	double getDamage() const
	{
		return damage;
	}
	double getArmor() const
	{
		return armor;
	}
	double getSpeed() const
	{
		return speed;
	}
	double getHealth() const 
	{
		return health;
	}
	double setHealth(double hl)
	{}
};