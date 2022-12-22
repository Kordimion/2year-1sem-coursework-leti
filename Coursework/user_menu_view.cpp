
#include <iostream>
#include <cstdio>
#include <conio.h>
#include "windows.h"

#include "flux_cpp.h"
#include "action_types.h"
#include "unit_store.h"
#include "game.h"
#include "console_helpers.h"
#include "field_store.h"

#include "views.h"

/**
* @brief Print main munu
*
* Prints menu to choose the option
*/
void printUserMenuView() {

	std::cout << "\nPlayer info:";
	auto player = PlayerStore::instance()->getCurrentPlayer();
	std::cout << "\nPlayer name: " << player->name;
	std::cout << "\nPlayer name: " << player->gold;
	std::cout << "\n-----------------------------";

	std::cout << "\nUser menu: press a key to enter a command";
	std::cout << "\n  " << "1. select unit";
	std::cout << "\n  " << "2. select field object";
	std::cout << "\n  " << "3. copy field";
	std::cout << "\n\n" << "Command:  ";

	std::cout << std::flush;
	char ch= _getch();
	std::cout << ch;

	if (ch == '1') {
		auto units = UnitStore::instance()->getUnits();
		auto iter = units.begin();
		if (units.empty()) DISPATCH(new IncorrectInputErrorAction("Can't select units if you don't have any"));
		else DISPATCH(new SelectUnitStartedAction());
	}
	else if (ch == '2') {
		DISPATCH(new FieldObjectSelectionStartedAction());
	}
	else if (ch  == '3') {
		copyField();
	}
	else 
		DISPATCH(new IncorrectInputErrorAction(std::string("[1/2/3/4] are allowed, but user pressed ") + ch));
}