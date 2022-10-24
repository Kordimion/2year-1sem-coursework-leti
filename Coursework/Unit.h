#pragma once
#include "Position.h"
#include "Player.h"
struct Unit {
	Position pos;
	const Player* player;
	Unit(const Player* _player, const Position& position)
	{
		player = _player;
		pos = position;
	}
	virtual char display() = 0;
	
};