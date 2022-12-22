#pragma once
#include <map>
#include "Position.h"
#include "Unit.h"
#include "unit_store.h"
#include "field_objects_store.h"
#include "field_store.h"

const bool isTileWithinUnitMovementReach(const Unit* unit, const Position& pos);

const std::map<Position, bool> getIsTileMoveableMap(
	const Field* field,
	const std::vector<FieldObject*>& fieldObjects,
	const std::vector<Unit*>& units
);

const bool getIsUnitMoveable(const Unit* unit);