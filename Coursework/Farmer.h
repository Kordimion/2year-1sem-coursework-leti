#pragma once
#include "Worker.h"
struct Farmer : public Worker {
	char display() override { return 'F'; };
};