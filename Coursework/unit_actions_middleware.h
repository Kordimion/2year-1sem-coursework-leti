#pragma once

#include "flux_cpp.h"
#include "action_types.h"
#include "Position.h"
#include "movement_validation.h"
#include "unit_store.h"

class UnitActionsMiddleware final : public flux_cpp::Middleware {
public:
	static UnitActionsMiddleware* instance() {
		static UnitActionsMiddleware* self = new UnitActionsMiddleware();
		return self;
	}

	std::shared_ptr<flux_cpp::Action> process(const std::shared_ptr<flux_cpp::Action>& action) override {
		auto actionType = action->getType<UnitActionTypes>();

		switch (actionType) {
		case UnitActionTypes::MoveUnit:
		{
			auto unit = UnitStore::instance()->getSelectedUnit();
			auto movementMap = getIsTileMoveableMap(FieldStore::instance()->getField(), FieldObjectsStore::instance()->getFieldObjects(), UnitStore::instance()->getUnits());
			auto pos = action->getPayload<Position>();

			bool isReachable = isTileWithinUnitMovementReach(unit, pos);
			bool isMoveable = movementMap[pos];

			if (isReachable && isMoveable) return action;
			else
			{
				if (!isReachable) 
					return std::shared_ptr<flux_cpp::Action> (
						new IncorrectInputErrorAction("Selected point is unreachable for unit")
					);
				if (!isMoveable) 
					return std::shared_ptr<flux_cpp::Action>(
						new IncorrectInputErrorAction("Selected unit can't move to this point")
					);
			}
			break;
		}
			
		}
		return action;
	}
private:
	UnitActionsMiddleware() = default;
};