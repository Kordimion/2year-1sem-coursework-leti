#pragma once
#include "Position.h"
struct Unit {
	Position pos;
	virtual char display() = 0;
};