#include "field_objects_store.h"
#include "relic.h"
#include "base.h"
#include "action_types.h"

void FieldObjectsStore::process(const std::shared_ptr<flux_cpp::Action>& action) {

	for (FieldObject* obj : _fieldObjects) {
		try {
			Relic* a = ((Relic*)(obj));
			switch (action->getType<UnitActionTypes>()) {
			case UnitActionTypes::DeleteUnit:
			{
				if (a->getHolder() == action->getPayload<Unit*>())
					DISPATCH(new DropRelicAction(const_cast<Relic*>(a)));		
			}
			case UnitActionTypes::MoveUnit:
			{
				auto payload = action->getPayload<MoveUnitPayload>();
				if (a->getHolder() == payload.unit)
					a->pos = payload.moveTo;

				auto it = std::find_if(_fieldObjects.begin(), _fieldObjects.end(), [payload, a](FieldObject* o) {
					try {
						Base* b = ((Base*)(o));
						if (b->pos == payload.moveTo && b->player == payload.unit->player) return true;
					}
					catch (std::bad_cast e) {
						return false;
					}
					});

				if (it != std::end(_fieldObjects)) DISPATCH(new RelicAcquiredAction(RelicAcquiredPayload(payload.unit->player, a)));
			}
			}
		}
		catch (std::bad_cast e) {
		}

	}

	switch (action->getType<FieldObjectActionType>()) {
	case FieldObjectActionType::Generated:
	{
		_fieldObjects = action->getPayload<std::vector<FieldObject*>>();
		break;
	}
	case FieldObjectActionType::SelectionStarted:
	{
		_fieldObjectSelectionActive = true;
		_selectedFieldObjectIndex = 0;
		if (_fieldObjects.empty()) {
			DISPATCH(new IncorrectInputErrorAction("There are no field objects to be selected"));
		}
		else {
			_fieldObjectSelectionActive = true;
		}
		break;
	}
	case FieldObjectActionType::SelectionStopped:
	{
		_fieldObjectSelectionActive = false;
		break;
	}
	case FieldObjectActionType::SelectedNext:
	{
		++_selectedFieldObjectIndex;
		break;
	}
	case FieldObjectActionType::SelectedPrevious:
	{
		--_selectedFieldObjectIndex;
		break;
	}
	case FieldObjectActionType::SetRelicHolder:
	{
		auto payload = action->getPayload<SetRelicHolderPayload>();
		const_cast<Relic*>(payload.relic)->setHolder(payload.holder);
		break;
	}
	case FieldObjectActionType::DropRelic:
	{
		auto payload = action->getPayload<Relic*>();
		payload->setHolder(nullptr);
		break;
	}
	case FieldObjectActionType::UnitEnteredTower:
	{
		auto payload = action->getPayload<UnitTowerActionPayload>();
		auto a = const_cast<Unit*>(payload.unit);
		const_cast<Tower*>(payload.tower)->addNewUnit(a);
		break;
	}
	case FieldObjectActionType::UnitLeftTower: 
	{
		auto payload = action->getPayload<UnitTowerActionPayload>();
		auto a = const_cast<Unit*>(payload.unit);
		const_cast<Tower*>(payload.tower)->popEnteredUnit(a);
		break;
	}
	}
}
