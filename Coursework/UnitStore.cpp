#include "UnitStore.h"


void UnitStore::process(const std::shared_ptr<flux_cpp::Action>& action)
{
	auto actionType = action->getType<UnitActionTypes>();
	UnitType unitType=UnitType::Farmer;
    Archer* a = new Archer();
	Farmer* f = new Farmer();
	Miner* m = new Miner();
	Slinger* l = new Slinger();
	Spearman* s = new Spearman();
	Swordsman* w = new Swordsman();
	switch (actionType)
	{
	case UnitActionTypes::SecectUnitType:

		unitType = action->getPayload<UnitType>();
		break;
	case UnitActionTypes::DeleteUnit:
		sko_unit->deleting(action->getPayload<Unit*>());
		break;
	case UnitActionTypes::AddUnit:

		switch (unitType)
		{
		case(UnitType::Archer):
			units.push_back(sko_unit->create(action->getPayload<Player>(), action->getPayload<Position>(), a));
			break;
		case(UnitType::Farmer):
			units.push_back(sko_unit->create(action->getPayload<Player>(), action->getPayload<Position>(), f));
			break;
		case(UnitType::Miner):
			units.push_back(sko_unit->create(action->getPayload<Player>(), action->getPayload<Position>(), m));
			break;
		case(UnitType::Slinger):
			units.push_back(sko_unit->create(action->getPayload<Player>(), action->getPayload<Position>(), l));
			break;
		case(UnitType::Spearman):
			units.push_back(sko_unit->create(action->getPayload<Player>(), action->getPayload<Position>(), s));
			break;
		case(UnitType::Sworsman):
			units.push_back(sko_unit->create(action->getPayload<Player>(), action->getPayload<Position>(), w));
			break;
		}

	

	}
}
