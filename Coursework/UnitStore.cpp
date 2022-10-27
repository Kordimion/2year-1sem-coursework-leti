#include "UnitStore.h"


void UnitStore::process(const std::shared_ptr<flux_cpp::Action>& action)
{
	auto actionType = action->getType<UnitActionTypes>();

	switch (actionType)
	{
	case UnitActionTypes::SelectUnitCreationType:
	{
		auto unitType = action->getPayload<UnitType>();
		switch (unitType)
		{
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
	case UnitActionTypes::AddUnit:
	{
		auto pos = action->getPayload<Position>();
		for (Unit* un : units)
		{
			if (un->pos == pos)
			{
				flux_cpp::Dispatcher::instance().dispatch(new flux_cpp::Action(ErrorActionTypes::IncorrectInputError, std::string("Unit in this position already exists")));
				return;
			}
		}
		units.push_back(unitFactory->create(PlayerStore::instance()->getCurrentPlayer(), pos));
		break;
	}
	case UnitActionTypes::SelectUnitStarted:
	{
		_unitSelectionActive = true;
		_unitSelectionIndex = 0;
		break;
	}
	case UnitActionTypes::SelectUnitStopped:
	{
		_unitSelectionActive = false;
		break;
	}
	case UnitActionTypes::SelectPreviousUnit:
	{
		_unitSelectionIndex = (_unitSelectionIndex - 1 + units.size()) % units.size();
		break;
	}
	case UnitActionTypes::SelectNextUnit:
	{
		_unitSelectionIndex = (_unitSelectionIndex + 1) % units.size();
		break;
	}
	case UnitActionTypes::DeleteSelectedUnit:
	{
		if (_unitSelectionActive == false) 
			flux_cpp::Dispatcher::instance().dispatch(new flux_cpp::Action(ErrorActionTypes::IncorrectInputError, std::string("can't delete unit if none is selected")));
		
		auto unitToDelete = units.begin() + _unitSelectionIndex;
		delete* unitToDelete;
		units.erase(unitToDelete, unitToDelete + 1);

		if(units.size() == 0)
			flux_cpp::Dispatcher::instance().dispatch(new flux_cpp::Action(UnitActionTypes::SelectUnitStopped));
		else 
			_unitSelectionIndex %= units.size();

		break;
	}
	case UnitActionTypes::MoveUnitStarted:
	{
		_unitMovementActive = true;
		break;
	}
	case UnitActionTypes::MoveUnit:
	{
		auto pos = action->getPayload<Position>();
		units[_unitSelectionIndex]->pos = pos;
		_unitMovementActive = false;
		break;
	}
	case UnitActionTypes::MoveUnitCanceled:
	{
		_unitMovementActive = false;
		break;
	}
	}
}