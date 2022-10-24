#include "UnitStore.h"



void UnitStore::process(const std::shared_ptr<flux_cpp::Action>& action)
{
	auto actionType = action->getType<UnitActionTypes>();

	switch (actionType)
	{
	case UnitActionTypes::SelectUnitType:
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
		
	}
}