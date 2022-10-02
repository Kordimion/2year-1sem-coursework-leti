#pragma once
#include "Unit.h"
struct Worker : public Unit {
	virtual char display() = 0;
};
