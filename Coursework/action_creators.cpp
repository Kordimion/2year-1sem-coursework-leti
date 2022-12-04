#include "flux_cpp.h"
#include "unit_type.h"
#include "action_types.h"
#include "position.h"
#include "field.h"
#include "field_generation.h"

void dispatchSelectUnitType(UnitType ut) {
	flux_cpp::Dispatcher::instance().dispatch(new flux_cpp::Action(UnitActionTypes::SelectUnitCreationType, ut));
}

void dispatchAddUnit(Position position) {
	flux_cpp::Dispatcher::instance().dispatch(new flux_cpp::Action(UnitActionTypes::AddUnit, position));
}

void dispatchStartUnitSelection() {
	flux_cpp::Dispatcher::instance().dispatch(new flux_cpp::Action(UnitActionTypes::SelectUnitStarted));
}

void dispatchNotImplemented(std::string message) {
	flux_cpp::Dispatcher::instance().dispatch(new flux_cpp::Action(ErrorActionTypes::NotImplementedError, std::string(message)));
}

void dispatchIncorrectInput(std::string message) {
	flux_cpp::Dispatcher::instance().dispatch(new flux_cpp::Action(ErrorActionTypes::IncorrectInputError, std::string(message)));
}

void dispatchFieldGenerated(unsigned int seed, int width, int height) {
	Field* field = new Field(height, width, generateLands(seed, width, height));
	flux_cpp::Dispatcher::instance().dispatch(new flux_cpp::Action(FieldActionTypes::FieldGenerated, field));	
}