#pragma once

#include <any>
#include <type_traits>
#include <utility>
#include "field.h"
#include "flux_cpp.h"
#include "unit_type.h"
#include "field_object.h"

#define DISPATCH(action) (flux_cpp::Dispatcher::instance().dispatch(action))

// Later there will be serialization logic, but it is needed for logging.
// Right now this name is meaningless, but later it will be useful
template<typename E>
using is_scoped_enum = std::integral_constant<bool, std::is_enum<E>::value && !std::is_convertible<E, int>::value>;
class SerializableAction : public flux_cpp::Action {
public:
	template <class ScopedEnum = typename std::enable_if<is_scoped_enum<ScopedEnum>::value>::type>
	SerializableAction(ScopedEnum type) : flux_cpp::Action(type) {};

	template <class ScopedEnum = typename std::enable_if<is_scoped_enum<ScopedEnum>::value>::type>
	SerializableAction(ScopedEnum type, std::any payload) : flux_cpp::Action(type, payload) {};
};

enum class GameFlowActionTypes {
	GameStarted = 1
};

struct GameStartedActionPayload {
	int fieldWidth, fieldHeight;
	unsigned int generationSeed;
	GameStartedActionPayload(unsigned int seed, int width, int height)
		: fieldWidth(width), fieldHeight(height), generationSeed(seed) {}
};

struct GameStartedAction : public SerializableAction {
	GameStartedAction(GameStartedActionPayload payload) : SerializableAction(GameFlowActionTypes::GameStarted, payload) {}
};

enum class FieldGenerationActionTypes {
	FieldGenerated = 5,
	FieldObjectsGenerated
};

struct FieldGeneratedAction : public SerializableAction {
	FieldGeneratedAction(Field* payload) : SerializableAction(FieldGenerationActionTypes::FieldGenerated, payload) {}
};

struct FieldObjectsGeneratedAction : public SerializableAction {
	FieldObjectsGeneratedAction(std::vector<FieldObject*>& payload) : SerializableAction(FieldGenerationActionTypes::FieldObjectsGenerated, payload) {}
};

enum class ErrorActionTypes {
	ErrorResolved = 10,
	NotImplementedError,
	IncorrectInputError
};

struct ErrorResolvedAction : public SerializableAction {
	ErrorResolvedAction() : SerializableAction(ErrorActionTypes::ErrorResolved) {}
};

struct NotImplementedErrorAction : public SerializableAction {
	NotImplementedErrorAction(std::string payload) : SerializableAction(ErrorActionTypes::NotImplementedError, payload) {}
};

struct IncorrectInputErrorAction : public SerializableAction {
	IncorrectInputErrorAction(std::string payload) : SerializableAction(ErrorActionTypes::IncorrectInputError, payload) {}
};

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
