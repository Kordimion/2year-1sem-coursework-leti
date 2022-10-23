#pragma once
#include "Position.h"
#include "Player.h"
struct Unit {
	Position pos;
	int playerId;
	Unit() = default;

	virtual char display() = 0;
};