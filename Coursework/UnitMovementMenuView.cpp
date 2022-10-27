#include "UnitMovementMenuView.h";

#include <iostream>
#include <conio.h>
#include "ActionTypes.h"
#include "flux_cpp.h"
#include "UnitStore.h"
#include "Windows.h"
#include "FieldView.h"

void gotoxy(int x, int y) {
	COORD pos = { (short int)x, (short int)y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

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

	int Keys;
	int poz_x = UnitStore::instance()->getSelectedUnit()->pos.x;
	int poz_y = UnitStore::instance()->getSelectedUnit()->pos.y;

	const int poz_x_offset = 1;
	const int poz_y_offset = 3;

	do
	{
		gotoxy(poz_x + poz_x_offset, poz_y + poz_y_offset);
		fflush(stdin);
		Keys = _getch();
		if (Keys == 'w' && poz_y > 0)
			poz_y--;
		else if (Keys == 'a' && poz_x > 0)
			poz_x--;
		else if (Keys == 's' && poz_y < FIELD_HEIGHT - 1)
			poz_y++;
		else if (Keys == 'd' && poz_x < FIELD_WIDTH - 1)
			poz_x++;
	} while (Keys == 'w' || Keys == 'a' || Keys == 's' || Keys == 'd');
	if (Keys == 'l')
		flux_cpp::Dispatcher::instance().dispatch(new flux_cpp::Action(UnitActionTypes::MoveUnit, Position{ poz_x,poz_y }));
	else
		flux_cpp::Dispatcher::instance().dispatch(new flux_cpp::Action(UnitActionTypes::MoveUnitCanceled));
}