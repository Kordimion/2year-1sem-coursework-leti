#include "movement_validation.h"
#include "field_store.h"
#include <map>
#include "unit_store.h"
#include "field_object.h"
#include "field_objects_store.h"

/**
* @brief Check if tiles moveable
*/
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
		res[unit->pos] &= getIsUnitMoveable(unit);

	for (const FieldObject* fieldObject : fieldObjects)
		res[fieldObject->pos] &= fieldObject->isWalkable();
	
	return res;
}

/**
* @brief Restricts unit steps
*/
const bool isTileWithinUnitMovementReach(const Unit* unit, const Position& pos)
{
	auto diffX = abs(unit->pos.x - pos.x);
	auto diffY = abs(unit->pos.y - pos.y);

	if (diffY + diffX <= unit->getStats()->getSpeed()) return true;
	return false;
}

/**
* @brief Check if unit can move
*/
const bool getIsUnitMoveable(const Unit* unit) {
	for (const FieldObject* fieldObject : FieldObjectsStore::instance()->getFieldObjects()) {
		try {
			const Tower* tower = dynamic_cast<const Tower*>(fieldObject);
			if (tower) {
				const auto indoorUnits = tower->getEnteredUnits();
				auto it = std::find(indoorUnits.begin(), indoorUnits.end(), unit);
				if (it != indoorUnits.end()) return false;
			}
		}
		catch (std::bad_cast e) {
		}
	}
	return true;
}