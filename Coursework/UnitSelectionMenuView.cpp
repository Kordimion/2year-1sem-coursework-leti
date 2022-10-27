#include "UnitSelectionMenuView.h";

#include <iostream>
#include <conio.h>
#include "ActionTypes.h"
#include "flux_cpp.h"
#include "UnitStore.h"

void printUnitSelectionMenuView() {
	std::cout << "\nUnit selection menu";
	std::cout << "\n-----------------------------";
	std::cout << "\nSelected unit type: "<< UnitStore::instance()->getSelectedUnit()->toString();
	std::cout << "\nStarting health: "<<UnitStore::instance()->getSelectedUnit()->getStats()->getStartingHealth();
	std::cout << "\nDamage: " << UnitStore::instance()->getSelectedUnit()->getStats()->getDamage();
	std::cout << "\nRange: " << UnitStore::instance()->getSelectedUnit()->getStats()->getRange();
	std::cout << "\nArmor: " << UnitStore::instance()->getSelectedUnit()->getStats()->getArmor();
	std::cout << "\nHealth: " << UnitStore::instance()->getSelectedUnit()->getStats()->getHealth();
	std::cout << "\nSpeed: " << UnitStore::instance()->getSelectedUnit()->getStats()->getSpeed();
	std::cout << "\nPress 'j'/'k' to select next/previous unit";
	std::cout << "\nPress 'd' to delete selected unit";
	std::cout << "\nPress any other key to leave";

	char Keys;
	
	fflush(stdin);
	Keys = _getch();
	if (Keys == 'j')
		flux_cpp::Dispatcher::instance().dispatch(new flux_cpp::Action(UnitActionTypes::SelectNextUnit));
	else if (Keys == 'k')
		flux_cpp::Dispatcher::instance().dispatch(new flux_cpp::Action(UnitActionTypes::SelectPreviousUnit));
	else if (Keys == 'd')
		flux_cpp::Dispatcher::instance().dispatch(new flux_cpp::Action(UnitActionTypes::DeleteSelectedUnit));
	else
		flux_cpp::Dispatcher::instance().dispatch(new flux_cpp::Action(UnitActionTypes::SelectUnitStopped));
}