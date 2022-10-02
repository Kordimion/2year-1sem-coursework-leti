#pragma once
#include "Ranger.h"
struct Archer : public Ranger {
	char display() override { return 'A'; };
};
