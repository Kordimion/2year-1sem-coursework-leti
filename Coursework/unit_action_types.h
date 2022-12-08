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
	DeleteUnit,
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

struct DeleteUnitAction : public SerializableAction {
	DeleteUnitAction(const Unit* payload) : SerializableAction(UnitActionTypes::DeleteUnit, payload) {}
	const std::string Serialize() const override { return "DeleteUnitAction|"; };
};

struct MoveUnitStartedAction : public SerializableAction {
	MoveUnitStartedAction() : SerializableAction(UnitActionTypes::MoveUnitStarted) {}
	const std::string Serialize() const override { return "MoveUnitStartedAction|"; };
};

struct MoveUnitPayload {
	Position moveTo;
	const Unit* unit;

	MoveUnitPayload(const Unit* u, Position mt) : unit(u), moveTo(mt) {};
};

struct MoveUnitAction : public SerializableAction {
	MoveUnitAction(MoveUnitPayload payload) : SerializableAction(UnitActionTypes::MoveUnit, payload) {}
	const std::string Serialize() const override { return std::string("MoveUnitAction|") + getPayload<MoveUnitPayload>().moveTo.toString(); };
};

struct MoveUnitCanceledAction : public SerializableAction {
	MoveUnitCanceledAction() : SerializableAction(UnitActionTypes::MoveUnitCanceled) {}
	const std::string Serialize() const override { return "MoveUnitCanceledAction|"; };
};
