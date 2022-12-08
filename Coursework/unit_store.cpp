#include "unit_store.h"

void UnitStore::process(const std::shared_ptr<flux_cpp::Action>& action) {
	auto actionType = action->getType<UnitActionTypes>();
	switch (actionType) {
	case UnitActionTypes::AddUnit:
	{	
		auto unit = action->getPayload<Unit*>();
		units.push_back(unit);
		break;
	}
	case UnitActionTypes::SelectUnitStarted: {
		_unitSelectionActive = true;
		_unitSelectionIndex = 0;
		break;
	}

	case UnitActionTypes::SelectUnitStopped: {
		_unitSelectionActive = false;
		_unitSelectionIndex = 0;
		break;
	}

	case UnitActionTypes::SelectPreviousUnit: {
		--_unitSelectionIndex;
		break;
	}

	case UnitActionTypes::SelectNextUnit: {
		++_unitSelectionIndex;
		break;
	}

	case UnitActionTypes::DeleteUnit: {
		auto it = std::find(units.begin(), units.end(), action->getPayload<const Unit*>());
		if(it != std::end(units)) units.erase(it, it + 1);

		if(units.size() == 0)
			DISPATCH(new SelectUnitStoppedAction());
		else 
			_unitSelectionIndex %= units.size();

		break;
	}

	case UnitActionTypes::MoveUnitStarted:	{
		_unitMovementActive = true;
		break;
	}
	case UnitActionTypes::MoveUnit:
	{
		auto payload = action->getPayload<MoveUnitPayload>();

		auto it = std::find(units.begin(), units.end(), payload.unit);
		if(it != std::end(units)) (*it)->pos = payload.moveTo;
		break;
	}

	case UnitActionTypes::MoveUnitCanceled:	{
		_unitMovementActive = false;
		break;
	}
	}
}