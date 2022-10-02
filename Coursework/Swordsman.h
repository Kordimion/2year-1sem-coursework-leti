#pragma once
#include "Warrior.h"
struct Swordsman : public Warrior {
	char display() override { return 'W'; };
};