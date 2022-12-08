#pragma once 

#include "serializable_action.h"
#include "field_object.h"
#include "relic.h"
#include "tower.h"

enum class FieldObjectActionType {
	Generated = 50,
	SelectionStarted,
	SelectionStopped,
	SelectedNext,
	SelectedPrevious,
	SetRelicHolder,
	DropRelic,
	RelicAcquired,
	UnitEnteredTower,
	UnitLeftTower
};

struct UnitTowerActionPayload {
	const Tower* tower;
	const Unit* unit;
	UnitTowerActionPayload(const Tower* t, const Unit* u) : tower(t), unit(u) {};
};

struct UnitEnteredTowerAction : public SerializableAction {
	UnitEnteredTowerAction(UnitTowerActionPayload payload) : SerializableAction(FieldObjectActionType::UnitEnteredTower, payload) {}
	const std::string Serialize() const override { return "UnitEnteredTowerAction|"; };
};

struct UnitLeftTowerAction : public SerializableAction {
	UnitLeftTowerAction(UnitTowerActionPayload payload) : SerializableAction(FieldObjectActionType::UnitLeftTower, payload) {}
	const std::string Serialize() const override { return "UnitLeftTowerAction|"; };
};

struct SetRelicHolderPayload {
	const Relic* relic;
	Unit* holder;
	SetRelicHolderPayload(const Relic* r, Unit* u) : relic(r), holder(u) {};
};

struct SetRelicHolderAction : public SerializableAction {
	SetRelicHolderAction(SetRelicHolderPayload payload) : SerializableAction(FieldObjectActionType::SetRelicHolder, payload) {}
	const std::string Serialize() const override { return "SetRelicHolderAction|"; };
};

struct RelicAcquiredPayload {
	const Relic* relic;
	const Player* player;
	RelicAcquiredPayload(const Player* p, const Relic* r) : player(p), relic(r) {};
};

struct RelicAcquiredAction : public SerializableAction {
	RelicAcquiredAction(RelicAcquiredPayload payload) : SerializableAction(FieldObjectActionType::RelicAcquired, payload) {}
	const std::string Serialize() const override { return "RelicAcquiredAction|"; };
};

struct DropRelicAction : public SerializableAction {
	DropRelicAction(Relic* payload) : SerializableAction(FieldObjectActionType::DropRelic, payload) {};
	const std::string Serialize() const override { return "DropRelic|"; };
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