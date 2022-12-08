#include <iostream>
#include <conio.h>

#include "action_types.h"
#include "flux_cpp.h"
#include "unit_store.h"

#include "views.h"
#include "field_objects_store.h"
#include "field_object.h"

void printUnitSelectionMenuView() {
	auto unit = UnitStore::instance()->getSelectedAffectedUnit();
	auto stats = unit.getStats();

	std::cout << "\nUnit selection menu";
	std::cout << "\n-----------------------------";
	std::cout << "\nSelected unit type: "<< unit.toString();
	std::cout << "\nStarting health: "<< stats->getStartingHealth();
	std::cout << "\nDamage: " << stats->getDamage();
	std::cout << "\nRange: " << stats->getRange();
	std::cout << "\nArmor: " << stats->getArmor();
	std::cout << "\nHealth: " << stats->getHealth();
	std::cout << "\nSpeed: " << stats->getSpeed();
	std::cout << "\n-----------------------------";

	auto fieldObjects = FieldObjectsStore::instance()->getFieldObjects();
	auto it = std::find_if(fieldObjects.begin(), fieldObjects.end(), [unit](FieldObject* obj) {
		return obj->pos == unit.pos;
		});

	if (it != std::end(fieldObjects)) {
		std::cout << "\nUnit & " << (*it)->fieldObjectName() << " interaction";
		std::cout << (*it)->interactionMessage();
	}

	std::cout << "\nPress 'j'/'k' to select next/previous unit";
	std::cout << "\nPress 'd' to delete selected unit";
	std::cout << "\nPress 'm' to move selected unit";
	std::cout << "\nPress any other key to leave";

	char Keys;
	
	fflush(stdin);
	Keys = _getch();
	if (Keys == 'j')
		DISPATCH(new SelectNextUnitAction());
	else if (Keys == 'k')
		DISPATCH(new SelectPreviousUnitAction());
	else if (Keys == 'd')
		DISPATCH(new DeleteSelectedUnitAction());
	else if (Keys == 'm')
		DISPATCH(new MoveUnitStartedAction());
	else if (it == std::end(fieldObjects) || !(*it)->interactionAction(unit))
		DISPATCH(new SelectUnitStoppedAction());
}