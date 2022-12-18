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
			auto payload = action->getPayload<MoveUnitPayload>();
			auto unit = payload.unit;
			auto movementMap = getIsTileMoveableMap(FieldStore::instance()->getField(), FieldObjectsStore::instance()->getFieldObjects(), UnitStore::instance()->getUnits());
			auto pos = payload.moveTo;

			bool isReachable = isTileWithinUnitMovementReach(unit, pos);
			bool isTileMoveable = movementMap[pos];
			bool isUnitMoveable = getIsUnitMoveable(unit);

			if (isReachable && isTileMoveable && isUnitMoveable) return action;
			else
			{
				if (!isReachable) 
					return std::shared_ptr<flux_cpp::Action> (
						new IncorrectInputErrorAction("Selected point is unreachable for unit")
					);
				if (!isTileMoveable) 
					return std::shared_ptr<flux_cpp::Action>(
						new IncorrectInputErrorAction("Selected unit can't move to this point")
					);
				if (!isUnitMoveable)
					return std::shared_ptr<flux_cpp::Action>(
						new IncorrectInputErrorAction("Selected unit can't be moved anywhere")
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