#pragma once
#include <map>
#include "Position.h"
#include "Unit.h"

const bool isTileWithinUnitMovementReach(const Unit* unit, const Position& pos);
const std::map<Position, bool> getIsTileMoveableMap();