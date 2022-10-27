#pragma once

#include "UnitStats.h"

class MinerStats: public UnitStats {
public:
	MinerStats() :UnitStats(12, 1, 2, 2, 1) {}
};