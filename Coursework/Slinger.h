#pragma once
#include "Ranger.h"
struct Slinger : public Ranger {
	char display() override { return 'L'; };
};
