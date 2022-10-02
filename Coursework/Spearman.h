#pragma once
#include "Warrior.h"
struct Spearman : public Warrior {
	char display() override { return 'S'; };
};
