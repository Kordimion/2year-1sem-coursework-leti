#include "movement_validation.h"
#include "field_store.h"
#include <map>
#include "unit_store.h"
#include "field_object.h"
#include "field_objects_store.h"

const std::map<Position, bool> getIsTileMoveableMap(
	const Field* field,
	const std::vector<FieldObject*>& fieldObjects,
	const std::vector<Unit*>& units
) {
	std::map<Position, bool> res;
	auto lands = field->getLands();
	auto width = field->getWidth();
	auto height = field->getHeight();

	for (int i = 0; i < width * height; ++i)
		res[Position(i % width, i / width)] = lands[i]->isWalkable();
	
	for (const Unit* unit : units)
		res[unit->pos] = false;

	for (const FieldObject* fieldObject : fieldObjects)
		res[fieldObject->pos] &= fieldObject->isWalkable();
	
	return res;
}

const bool isTileWithinUnitMovementReach(const Unit* unit, const Position& pos)
{
	auto diffX = abs(unit->pos.x - pos.x);
	auto diffY = abs(unit->pos.y - pos.y);

	if (diffY + diffX <= unit->getStats()->getRange()) return true;
	return false;
}