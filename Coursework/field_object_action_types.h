#pragma once 

#include "serializable_action.h"
#include "field_object.h"

enum class FieldObjectActionType {
	Generated = 50,
	SelectionStarted,
	SelectionStopped,
	SelectedNext,
	SelectedPrevious
};

struct FieldObjectsGeneratedAction : public SerializableAction {
	FieldObjectsGeneratedAction(std::vector<FieldObject*>& payload) : SerializableAction(FieldObjectActionType::Generated, payload) {}
};

struct FieldObjectSelectionStartedAction : public SerializableAction {
	FieldObjectSelectionStartedAction() : SerializableAction(FieldObjectActionType::SelectionStarted) {}
};

struct FieldObjectSelectionStoppedAction : public SerializableAction {
	FieldObjectSelectionStoppedAction() : SerializableAction(FieldObjectActionType::SelectionStopped) {}
};

struct FieldObjectSelectedNextAction : public SerializableAction {
	FieldObjectSelectedNextAction() : SerializableAction(FieldObjectActionType::SelectedNext) {}
};

struct FieldObjectSelectedPreviousAction : public SerializableAction {
	FieldObjectSelectedPreviousAction() : SerializableAction(FieldObjectActionType::SelectedPrevious) {}
};