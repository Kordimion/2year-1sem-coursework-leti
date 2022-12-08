#pragma once 

#include "serializable_action.h"
#include "unit_type.h"
#include "unit.h"

enum class UnitActionTypes {
	SelectUnitCreationType = 20,
	AddUnit,
	SelectUnitStarted,
	SelectUnitStopped,
	SelectNextUnit,
	SelectPreviousUnit,
	DeleteSelectedUnit,
	MoveUnitStarted,
	MoveUnit,
	MoveUnitCanceled
};

struct SelectUnitCreationTypeAction : public SerializableAction {
	const std::string Serialize() const override { return "SelectUnitCreationTypeAction|"; };
	SelectUnitCreationTypeAction(UnitType payload) : SerializableAction(UnitActionTypes::SelectUnitCreationType, payload) {}
};

struct AddUnitAction : public SerializableAction {
	AddUnitAction(Position payload) : SerializableAction(UnitActionTypes::AddUnit, payload) {}
	const std::string Serialize() const override { return std::string("AddUnitAction|") + getPayload<Position>().toString(); };
};

struct SelectUnitStartedAction : public SerializableAction {
	SelectUnitStartedAction() : SerializableAction(UnitActionTypes::SelectUnitStarted) {}
	const std::string Serialize() const override { return "SelectUnitStartedAction|"; };
};

struct SelectUnitStoppedAction : public SerializableAction {
	SelectUnitStoppedAction() : SerializableAction(UnitActionTypes::SelectUnitStopped) {}
	const std::string Serialize() const override { return "SelectUnitStoppedAction|"; };
};

struct SelectNextUnitAction : public SerializableAction {
	SelectNextUnitAction() : SerializableAction(UnitActionTypes::SelectNextUnit) {}
	const std::string Serialize() const override { return "SelectNextUnitAction|"; };
};

struct SelectPreviousUnitAction : public SerializableAction {
	SelectPreviousUnitAction() : SerializableAction(UnitActionTypes::SelectPreviousUnit) {}
	const std::string Serialize() const override { return "SelectPreviousUnitAction|"; };
};

struct DeleteSelectedUnitAction : public SerializableAction {
	DeleteSelectedUnitAction() : SerializableAction(UnitActionTypes::DeleteSelectedUnit) {}
	const std::string Serialize() const override { return "DeleteSelectedUnitAction|"; };
};

struct MoveUnitStartedAction : public SerializableAction {
	MoveUnitStartedAction() : SerializableAction(UnitActionTypes::MoveUnitStarted) {}
	const std::string Serialize() const override { return "MoveUnitStartedAction|"; };
};

struct MoveUnitAction : public SerializableAction {
	MoveUnitAction(Position payload) : SerializableAction(UnitActionTypes::MoveUnit, payload) {}
	const std::string Serialize() const override { return std::string("MoveUnitAction|") + getPayload<Position>().toString(); };
};

struct MoveUnitCanceledAction : public SerializableAction {
	MoveUnitCanceledAction() : SerializableAction(UnitActionTypes::MoveUnitCanceled) {}
	const std::string Serialize() const override { return "MoveUnitCanceledAction|"; };
};
