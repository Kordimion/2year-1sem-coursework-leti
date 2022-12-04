#include <iostream>
#include <conio.h>

#include "action_types.h"
#include "flux_cpp.h"
#include "unit_store.h"
#include "unit_selection_menu_view.h"


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
	std::cout << "\n-----------------------------";
	std::cout << "\nPress 'j'/'k' to select next/previous unit";
	std::cout << "\nPress 'd' to delete selected unit";
	std::cout << "\nPress 'm' to move selected unit";
	std::cout << "\nPress any other key to leave";

	char Keys;
	
	//TODO -> to action_creators

	fflush(stdin);
	Keys = _getch();
	if (Keys == 'j')
		flux_cpp::Dispatcher::instance().dispatch(new flux_cpp::Action(UnitActionTypes::SelectNextUnit));
	else if (Keys == 'k')
		flux_cpp::Dispatcher::instance().dispatch(new flux_cpp::Action(UnitActionTypes::SelectPreviousUnit));
	else if (Keys == 'd')
		flux_cpp::Dispatcher::instance().dispatch(new flux_cpp::Action(UnitActionTypes::DeleteSelectedUnit));
	else if (Keys == 'm')
		flux_cpp::Dispatcher::instance().dispatch(new flux_cpp::Action(UnitActionTypes::MoveUnitStarted));
	else
		flux_cpp::Dispatcher::instance().dispatch(new flux_cpp::Action(UnitActionTypes::SelectUnitStopped));
}