
#include <iostream>
#include <cstdio>
#include <conio.h>
#include "windows.h"

#include "flux_cpp.h"
#include "action_types.h"
#include "unit_type.h"
#include "unit_store.h"
#include "game.h"
#include "console_helpers.h"
#include "field_store.h"

#include "views.h"

void printUserMenuView() {
	std::cout << "\nUser menu: press a key to enter a command";
	std::cout << "\n  " << "1. add unit(" << UnitStore::instance()->getUnitFactory()->toString() << ")";
	std::cout << "\n  " << "2. select unit type";
	std::cout << "\n  " << "3. select unit";
	std::cout << "\n  " << "4. select field object";
	std::cout << "\n  " << "5. copy field";
	std::cout << "\n\n" << "Command:  ";

	std::cout << std::flush;
	char ch= _getch();
	std::cout << ch;

	if (ch == '1') {
		char key;
		Position pos;

		auto field = FieldStore::instance()->getField();

		do {
			gotoxy(pos.x+offsetX, pos.y+offsetY);
			fflush(stdin);
			key = _getch();
			if (key == 'w' && pos.y>0)
				pos.y--;
			else if (key == 'a' && pos.x>0)
				pos.x--;
			else if (key == 's' && pos.y<field->getHeight()-1)
				pos.y++;
			else if (key == 'd' && pos.x<field->getWidth()-1)
				pos.x++;
		} while (key != 'l');

		DISPATCH(new AddUnitAction(pos));
	}
	else if (ch == '2') {
		std::cout << "\nUser menu: press a key to select the unit type";
		std::cout << "\n  " << "1. Archer";
		std::cout << "\n  " << "2. Farmer";
		std::cout << "\n  " << "3. Miner";
		std::cout << "\n  " << "4. Slinger";
		std::cout << "\n  " << "5. Swordsman";
		std::cout << "\n  " << "6. Spearman";
		std::cout << "\n\n" << "Command:  ";

		std::cout << std::flush;
		char ch = _getch();
		if (ch == '1')
			DISPATCH(new SelectUnitCreationTypeAction(UnitType::Archer));
		else if (ch  == '2')
			DISPATCH(new SelectUnitCreationTypeAction(UnitType::Farmer));
		else if (ch == '3')
			DISPATCH(new SelectUnitCreationTypeAction(UnitType::Miner));
		else if (ch == '4')
			DISPATCH(new SelectUnitCreationTypeAction(UnitType::Slinger));
		else if (ch  == '5')
			DISPATCH(new SelectUnitCreationTypeAction(UnitType::Sworsman));
		else if (ch  == '6')
			DISPATCH(new SelectUnitCreationTypeAction(UnitType::Spearman));
		else
			DISPATCH(new IncorrectInputErrorAction(std::string("[1/2/3/4/5/6] are allowed, but user pressed ") + ch));
	}
	else if (ch == '3') {
		auto units = UnitStore::instance()->getUnits();
		auto iter = units.begin();
		if (units.empty()) DISPATCH(new IncorrectInputErrorAction("Can't select units if you don't have any"));
		else DISPATCH(new SelectUnitStartedAction());
	}
	else if (ch == '4') {
		DISPATCH(new FieldObjectSelectionStartedAction());
	}
	else if (ch  == '5') {
		copyField();
	}
	else 
		DISPATCH(new IncorrectInputErrorAction(std::string("[1/2/3/4] are allowed, but user pressed ") + ch));
}