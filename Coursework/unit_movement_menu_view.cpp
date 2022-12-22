#include <iostream>
#include <conio.h>
#include "windows.h"

#include "action_types.h"
#include "flux_cpp.h"
#include "unit_store.h"
#include "console_helpers.h"
#include "field_store.h"

#include "views.h"

/**
* @brief Print movement menu
*
* Prints menu to control the movement of the unit
*/
void printUnitMovementMenuView() {
	auto unit = UnitStore::instance()->getSelectedAffectedUnit();
	auto unaffectedUnit = UnitStore::instance()->getSelectedUnit();
	auto stats = unit->getStats();
	std::cout << "\nUnit movement menu";
	std::cout << "\n-----------------------------";
	std::cout << "\nSelected unit type: " << unit->toString();
	std::cout << "\nStarting health: " << stats->getStartingHealth();
	std::cout << "\nDamage: " << stats->getDamage();
	std::cout << "\nRange: " << stats->getRange();
	std::cout << "\nArmor: " << stats->getArmor();
	std::cout << "\nHealth: " << stats->getHealth();
	std::cout << "\nSpeed: " << stats->getSpeed();
	std::cout << "\n-----------------------------";
	std::cout << "\nPress 'w'/'a'/'s'/'d' to move unit target position";
	std::cout << "\nPress 'l' to confirm unit movement position";
	std::cout << "\nPress any other key to leave";

	char key;
	Position pos= UnitStore::instance()->getSelectedAffectedUnit()->pos;
	
	do {
		auto field = FieldStore::instance()->getField();

		gotoxy(pos.x + offsetX, pos.y + offsetY);
		fflush(stdin);
		key = _getch();
		if (key == 'w' && pos.y > 0)
			pos.y--;
		else if (key == 'a' && pos.x > 0)
			pos.x--;
		else if (key == 's' && pos.y < field->getHeight() - 1)
			pos.y++;
		else if (key == 'd' && pos.x < field->getWidth() - 1)
			pos.x++;
	} while (key == 'w' || key == 'a' || key == 's' || key == 'd');

	
	if (key == 'l')
		DISPATCH(new MoveUnitAction(MoveUnitPayload(unaffectedUnit, pos)));
	else
		DISPATCH(new MoveUnitCanceledAction());
}