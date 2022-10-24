#include "UserMenuView.h"
#include <iostream>
#include <cstdio>
#include "flux_cpp.h"
#include "ActionTypes.h"



void dispatchNotImplemented(std::string message) {
	flux_cpp::Dispatcher::instance().dispatch(new flux_cpp::Action(ErrorActionTypes::NotImplementedError, std::string(message)));
}

void dispatchIncorrectInput(std::string message) {
	flux_cpp::Dispatcher::instance().dispatch(new flux_cpp::Action(ErrorActionTypes::IncorrectInputError, std::string(message)));
}

void printUserMenuView() {
	std::cout << "\nUser menu: press a key to enter a command";
	std::cout << "\n  " << "1. add unit";
	std::cout << "\n  " << "2. select unit type";
	std::cout << "\n  " << "3. select unit";
	std::cout << "\n  " << "4. copy field";
	std::cout << "\n\n" << "Command:  ";

	std::cout << std::flush;
	char ch[10];
	std::cin.getline(ch, 10);

	if (ch[0] == '1') 
		dispatchNotImplemented("add unit");
	else if (ch[0] == '2') 
		dispatchNotImplemented("select unit type");
	else if (ch[0] == '3') 
		dispatchNotImplemented("select unit");
	else if (ch[0] == '4') 
		dispatchNotImplemented("copy field");
	else 
		dispatchIncorrectInput(std::string("[1/2/3/4] are allowed, but user pressed ") + ch[0]);
}