#pragma once

#include "base.h"
#include "action_types.h"
#include "console_helpers.h"
#include "field_store.h"
#include <conio.h>
#include <iostream>

#include "archer_factory.h"
#include "miner_factory.h"
#include "swordsman_factory.h"
#include "spearman_factory.h"
#include "slinger_factory.h"
#include "farmer_factory.h"

/*
UnitBought
BaseUnitFactorySelected
*/
const std::string const Base::selectionMessage() const {
	std::string res;

	res += "\nBase belongs to user ";
	res += player->name;
	res += "\npress 1 to buy a unit";
	res += "\npress 2 to select a unit factory";

	return res;
}
/**
* @brief Base main menu
*/
const bool Base::selectionAction(std::any payload) const {
	std::string res;

	auto key = std::any_cast<char>(payload);
	
	if (key == '1')
	{
		char key;
		Position pos;
		auto field = FieldStore::instance()->getField();
		
		DISPATCH(new UnitBoughtAction(BaseUnitFactorySelectedPayload(this->factory, this)));
		return true;
	}
	else if (key == '2') {
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
			flux_cpp::Dispatcher::instance().dispatch((new BaseUnitFactorySelectedAction(BaseUnitFactorySelectedPayload(new ArcherFactory, this))));
		else if (ch == '2')
			DISPATCH((new BaseUnitFactorySelectedAction(BaseUnitFactorySelectedPayload(new FarmerFactory, this))));
		else if (ch == '3')
			DISPATCH((new BaseUnitFactorySelectedAction(BaseUnitFactorySelectedPayload(new MinerFactory, this))));
		else if (ch == '4')
			DISPATCH((new BaseUnitFactorySelectedAction(BaseUnitFactorySelectedPayload(new SlingerFactory, this))));
		else if (ch == '5')
			DISPATCH((new BaseUnitFactorySelectedAction(BaseUnitFactorySelectedPayload(new SwordsmanFactory, this))));
		else if (ch == '6')
			DISPATCH((new BaseUnitFactorySelectedAction(BaseUnitFactorySelectedPayload(new SpearmanFactory, this))));
		else
			DISPATCH(new IncorrectInputErrorAction(std::string("[1/2/3/4/5/6] are allowed, but user pressed ") + ch));
		return true;
	}
	return false;
}