#include "field_objects_store.h"

void FieldObjectsStore::process(const std::shared_ptr<flux_cpp::Action>& action) {
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
	}
}
