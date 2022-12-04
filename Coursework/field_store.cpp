#include "field_store.h";
#include "action_creators.h"

void FieldStore::process(const std::shared_ptr<flux_cpp::Action>& action) {
	switch (action->getType<FieldActionTypes>()) {
	case FieldActionTypes::FieldGenerated:
		_field = action->getPayload<Field*>();
		break;
	}
}
