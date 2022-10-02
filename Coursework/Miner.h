#pragma once
#include "Worker.h"
struct Miner : public Worker {
	char display() override { return 'M'; };
};
