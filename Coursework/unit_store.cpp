#include "unit_store.h"

void UnitStore::process(const std::shared_ptr<flux_cpp::Action>& action) {
	auto actionType = action->getType<UnitActionTypes>();

	switch (actionType) {
	case UnitActionTypes::SelectUnitCreationType: {
		auto unitType = action->getPayload<UnitType>();

		switch (unitType){
		case UnitType::Archer:
			delete unitFactory;
			unitFactory = new ArcherFactory;
			break;

		case UnitType::Farmer:
			delete unitFactory;
			unitFactory = new FarmerFactory;
			break;

		case UnitType::Slinger:
			delete unitFactory;
			unitFactory = new SlingerFactory;
			break;

		case UnitType::Sworsman:
			delete unitFactory;
			unitFactory = new SwordsmanFactory;
			break;

		case UnitType::Spearman:
			delete unitFactory;
			unitFactory = new SpearmanFactory;
			break;

		case UnitType::Miner:
			delete unitFactory;
			unitFactory = new MinerFactory;
			break;
		}
		break;
	}

	case UnitActionTypes::AddUnit:{
		auto pos = action->getPayload<Position>();

		for (Unit* un : units) {
			if (un->pos == pos) {
				DISPATCH(new IncorrectInputErrorAction("Unit in this position already exists"));
				return;
			}	
		}
		units.push_back(unitFactory->create(PlayerStore::instance()->getCurrentPlayer(), pos));
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