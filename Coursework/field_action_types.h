#pragma once

#include "serializable_action.h"
#include "field.h"

enum class FieldActionTypes {
	FieldGenerated = 5
};

struct FieldGeneratedAction : public SerializableAction {
	FieldGeneratedAction(Field* payload) : SerializableAction(FieldActionTypes::FieldGenerated, payload) {}
};
