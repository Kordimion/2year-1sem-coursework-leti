#include "UserMenuView.h"
#include <iostream>
#include <cstdio>
#include "flux_cpp.h"
#include "ActionTypes.h"
#include "UnitType.h"
#include "UnitStore.h"
#include "windows.h"
#include <conio.h>
#include "FieldView.h"


void dispatchSelectUnitType(UnitType ut) 
{
	flux_cpp::Dispatcher::instance().dispatch(new flux_cpp::Action(UnitActionTypes::SelectUnitType,ut));
}
void dispatchAddUnit(Position position)
{
	flux_cpp::Dispatcher::instance().dispatch(new flux_cpp::Action(UnitActionTypes::AddUnit, position));
}

void dispatchNotImplemented(std::string message) {
	flux_cpp::Dispatcher::instance().dispatch(new flux_cpp::Action(ErrorActionTypes::NotImplementedError, std::string(message)));
}

void dispatchIncorrectInput(std::string message) {
	flux_cpp::Dispatcher::instance().dispatch(new flux_cpp::Action(ErrorActionTypes::IncorrectInputError, std::string(message)));
}

void gotoxy(int x, int y) {
	COORD pos = {(short int) x, (short int)y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

void printUserMenuView() {
	std::cout << "\nUser menu: press a key to enter a command";
	std::cout << "\n  " << "1. add unit(" << UnitStore::instance()->getUnitFactory()->toString() << ")";
	std::cout << "\n  " << "2. select unit type";
	std::cout << "\n  " << "3. select unit";
	std::cout << "\n  " << "4. copy field";
	std::cout << "\n\n" << "Command:  ";

	std::cout << std::flush;
	char ch[10];
	std::cin.getline(ch, 10);

	if (ch[0] == '1')
	{
		int Keys;
		int poz_x = 0;
		int poz_y = 0;
		const int poz_x_offset = 1;
		const int poz_y_offset = 3;
		
		do
		{
			gotoxy(poz_x+poz_x_offset, poz_y+poz_y_offset);
			fflush(stdin);
			Keys = _getch();
			if (Keys == 'w' && poz_y>0)
				poz_y--;
			else if (Keys == 'a' && poz_x>0)
				poz_x--;
			else if (Keys == 's' && poz_y<FIELD_HEIGHT-1)
				poz_y++;
			else if (Keys == 'd' && poz_x<FIELD_WIDTH-1)
				poz_x++;
		} while (Keys != 'l');
		dispatchAddUnit({poz_x,poz_y});
		
	}

	else if (ch[0] == '2')
	{
		std::cout << "\nUser menu: press a key to select the unit type";
		std::cout << "\n  " << "1. Archer";
		std::cout << "\n  " << "2. Farmer";
		std::cout << "\n  " << "3. Miner";
		std::cout << "\n  " << "4. Slinger";
		std::cout << "\n  " << "5. Swordsman";
		std::cout << "\n  " << "6. Spearman";
		std::cout << "\n\n" << "Command:  ";

		std::cout << std::flush;
		char ch[10];
		std::cin.getline(ch, 10);
		if (ch[0] == '1')
			dispatchSelectUnitType(UnitType::Archer);
		else if (ch[0] == '2')
			dispatchSelectUnitType(UnitType::Farmer);
		else if (ch[0] == '3')
			dispatchSelectUnitType(UnitType::Miner);
		else if (ch[0] == '4')
			dispatchSelectUnitType(UnitType::Slinger);
		else if (ch[0] == '5')
			dispatchSelectUnitType(UnitType::Sworsman);
		else if (ch[0] == '6')
			dispatchSelectUnitType(UnitType::Spearman);
		else
			dispatchIncorrectInput(std::string("[1/2/3/4/5/6] are allowed, but user pressed ") + ch[0]);
	}
	else if (ch[0] == '3') 
		dispatchNotImplemented("select unit");
	else if (ch[0] == '4') 
		dispatchNotImplemented("copy field");
	else 
		dispatchIncorrectInput(std::string("[1/2/3/4] are allowed, but user pressed ") + ch[0]);
}