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

	const std::string Serialize() const override { return "FieldObjectsGeneratedAction|"; };
};

struct FieldObjectSelectionStartedAction : public SerializableAction {
	FieldObjectSelectionStartedAction() : SerializableAction(FieldObjectActionType::SelectionStarted) {}
	
	const std::string Serialize() const override { return "FieldObjectSelectionStartedAction|"; };
};

struct FieldObjectSelectionStoppedAction : public SerializableAction {
	FieldObjectSelectionStoppedAction() : SerializableAction(FieldObjectActionType::SelectionStopped) {}
	const std::string Serialize() const override { return "FieldObjectSelectionStoppedAction|"; };
};

struct FieldObjectSelectedNextAction : public SerializableAction {
	FieldObjectSelectedNextAction() : SerializableAction(FieldObjectActionType::SelectedNext) {}
	const std::string Serialize() const override { return "FieldObjectSelectedNextAction|"; };
};

struct FieldObjectSelectedPreviousAction : public SerializableAction {
	FieldObjectSelectedPreviousAction() : SerializableAction(FieldObjectActionType::SelectedPrevious) {}
	const std::string Serialize() const override { return "FieldObjectSelectedPreviousAction|"; };
};