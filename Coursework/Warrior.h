#pragma once
#include "Unit.h"
struct Warrior : public Unit {
	virtual char display() = 0;
};
