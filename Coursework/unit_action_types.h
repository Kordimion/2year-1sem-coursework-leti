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
	SelectUnitCreationTypeAction(UnitType payload) : SerializableAction(UnitActionTypes::SelectUnitCreationType, payload) {}
};

struct AddUnitAction : public SerializableAction {
	AddUnitAction(Position payload) : SerializableAction(UnitActionTypes::AddUnit, payload) {}
};

struct SelectUnitStartedAction : public SerializableAction {
	SelectUnitStartedAction() : SerializableAction(UnitActionTypes::SelectUnitStarted) {}
};

struct SelectUnitStoppedAction : public SerializableAction {
	SelectUnitStoppedAction() : SerializableAction(UnitActionTypes::SelectUnitStopped) {}
};

struct SelectNextUnitAction : public SerializableAction {
	SelectNextUnitAction() : SerializableAction(UnitActionTypes::SelectNextUnit) {}
};

struct SelectPreviousUnitAction : public SerializableAction {
	SelectPreviousUnitAction() : SerializableAction(UnitActionTypes::SelectPreviousUnit) {}
};

struct DeleteSelectedUnitAction : public SerializableAction {
	DeleteSelectedUnitAction() : SerializableAction(UnitActionTypes::DeleteSelectedUnit) {}
};

struct MoveUnitStartedAction : public SerializableAction {
	MoveUnitStartedAction() : SerializableAction(UnitActionTypes::MoveUnitStarted) {}
};

struct MoveUnitAction : public SerializableAction {
	MoveUnitAction(Position payload) : SerializableAction(UnitActionTypes::MoveUnit, payload) {}
};

struct MoveUnitCanceledAction : public SerializableAction {
	MoveUnitCanceledAction() : SerializableAction(UnitActionTypes::MoveUnitCanceled) {}
};
