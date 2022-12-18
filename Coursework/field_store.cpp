#include "field_store.h";

void FieldStore::process(const std::shared_ptr<flux_cpp::Action>& action) {
	switch (action->getType<FieldGenerationActionTypes>()) {
	case FieldGenerationActionTypes::FieldGenerated:
		_field = action->getPayload<Field*>();
		break;
	}
}
