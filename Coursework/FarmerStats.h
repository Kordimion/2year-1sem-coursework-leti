#pragma once

#include "UnitStats.h"

class FarmerStats : public UnitStats {
public:
	FarmerStats() :UnitStats(15, 1, 3, 1, 1) {}
};