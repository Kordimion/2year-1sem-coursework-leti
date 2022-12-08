#include "field_objects_store.h"

void FieldObjectsStore::process(const std::shared_ptr<flux_cpp::Action>& action) {
	switch (action->getType<FieldObjectActionType>()) {
	case FieldObjectActionType::FieldObjectsGenerated:
		_fieldObjects = action->getPayload<std::vector<FieldObject*>>();
		break;
	}
}
