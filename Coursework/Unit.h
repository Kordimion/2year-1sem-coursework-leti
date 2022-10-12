#pragma once
#include "Position.h"
struct Unit {
	Position pos;
	int playerId;
	virtual char display() = 0;
};