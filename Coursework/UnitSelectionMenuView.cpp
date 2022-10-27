#include "UnitSelectionMenuView.h";

#include <iostream>
#include <conio.h>
#include "ActionTypes.h"
#include "flux_cpp.h"

void printUnitSelectionMenuView() {
	std::cout << "\nUnit selection menu";
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