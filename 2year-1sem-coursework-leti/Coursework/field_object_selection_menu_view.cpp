#include "views.h"
#include "field_object.h"
#include "field_objects_store.h"
#include <iostream>
#include "action_types.h"
#include <conio.h>
#include "player_store.h"

/**
* @brief Prints menu for object selection
*/
void printFieldObjectSelectionMenuView() {
	auto selectedFieldObject = FieldObjectsStore::instance()->getSelectedFieldObject();
	std::cout << "\nField Object Selection menu";
	std::cout << "\n-----------------------------";
	std::cout << "\nPlayer info:";
	auto player = PlayerStore::instance()->getCurrentPlayer();
	std::cout << "\nPlayer name: " << player->name;
	std::cout << "\nPlayer name: " << player->gold;
	std::cout << "\n-----------------------------";
	std::cout << "\nSelected Field Object: " << selectedFieldObject->fieldObjectName();
	std::cout << selectedFieldObject->selectionMessage();
	std::cout << "\nPress 'j'/'k' to select next/previous field object";
	std::cout << "\nPress any other key to leave";
	
	char key;
	key = _getch();
	if (key == 'j') DISPATCH(new FieldObjectSelectedNextAction());
	else if (key == 'k') DISPATCH(new FieldObjectSelectedPreviousAction());
	else if(!selectedFieldObject->selectionAction(key)) 
		DISPATCH(new FieldObjectSelectionStoppedAction());
}