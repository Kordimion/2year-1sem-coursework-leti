#pragma once

#include "UnitStats.h"

class ArcherStats: public UnitStats{
public:
	ArcherStats() :UnitStats(15, 5, 6, 2, 2){}
};