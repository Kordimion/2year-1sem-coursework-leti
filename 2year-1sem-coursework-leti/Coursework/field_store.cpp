#include "field_store.h";

/**
* @brief Take generated field
*/
void FieldStore::process(const std::shared_ptr<flux_cpp::Action>& action) {
	switch (action->getType<FieldActionTypes>()) {
	case FieldActionTypes::FieldGenerated:
		_field = action->getPayload<Field*>();
		break;
	}
}
