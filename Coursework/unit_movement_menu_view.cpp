#include <iostream>
#include <conio.h>
#include "Windows.h"

#include "action_types.h"
#include "flux_cpp.h"
#include "unit_store.h"
#include "field_view.h"
#include "unit_movement_menu_view.h"
#include "console_helpers.h"


void printUnitMovementMenuView() {
	std::cout << "\nUnit movement menu";
	std::cout << "\n-----------------------------";
	std::cout << "\nSelected unit type: " << UnitStore::instance()->getSelectedUnit()->toString();
	std::cout << "\nStarting health: " << UnitStore::instance()->getSelectedUnit()->getStats()->getStartingHealth();
	std::cout << "\nDamage: " << UnitStore::instance()->getSelectedUnit()->getStats()->getDamage();
	std::cout << "\nRange: " << UnitStore::instance()->getSelectedUnit()->getStats()->getRange();
	std::cout << "\nArmor: " << UnitStore::instance()->getSelectedUnit()->getStats()->getArmor();
	std::cout << "\nHealth: " << UnitStore::instance()->getSelectedUnit()->getStats()->getHealth();
	std::cout << "\nSpeed: " << UnitStore::instance()->getSelectedUnit()->getStats()->getSpeed();
	std::cout << "\n-----------------------------";
	std::cout << "\nPress 'w'/'a'/'s'/'d' to move unit target position";
	std::cout << "\nPress 'l' to confirm unit movement position";
	std::cout << "\nPress any other key to leave";

	char key;
	Position pos= UnitStore::instance()->getSelectedUnit()->pos;
	
	do {
		gotoxy(pos.x + offsetX, pos.y + offsetY);
		fflush(stdin);
		key = _getch();
		if (key == 'w' && pos.y > 0)
			pos.y--;
		else if (key == 'a' && pos.x > 0)
			pos.x--;
		else if (key == 's' && pos.y < FIELD_HEIGHT - 1)
			pos.y++;
		else if (key == 'd' && pos.x < FIELD_WIDTH - 1)
			pos.x++;
	} while (key == 'w' || key == 'a' || key == 's' || key == 'd');

	
	if (key == 'l')
		flux_cpp::Dispatcher::instance().dispatch(new flux_cpp::Action(UnitActionTypes::MoveUnit, pos));
	else
		flux_cpp::Dispatcher::instance().dispatch(new flux_cpp::Action(UnitActionTypes::MoveUnitCanceled));
}