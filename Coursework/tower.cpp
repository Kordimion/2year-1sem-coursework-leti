#include "tower.h"
#include "action_types.h"

/**
* @brief Give interaction menu
*/
const std::string Tower::interactionMessage(std::any payload) const {
	auto unit = std::any_cast<Unit*>(payload);
	auto it = std::find(_enteredUnits.begin(), _enteredUnits.end(), unit);
	if (it != _enteredUnits.end()) {
		return "\nPress 1 to leave the tower";
	}
	else {
		return "\nPress 1 to enter the tower";
	}
}

/**
* @brief For interact with tower
*/
const bool Tower::interactionAction(std::any payload) const  {
	auto p = std::any_cast<std::pair<Unit*, char>>(payload);
	auto unit = p.first;
	auto key = p.second;

	if (key == '1') {
		auto it = std::find(_enteredUnits.begin(), _enteredUnits.end(), unit);
		if (it != _enteredUnits.end()) {
			DISPATCH(new UnitLeftTowerAction(UnitTowerActionPayload(this, unit)));
		}
		else {
			DISPATCH(new UnitEnteredTowerAction(UnitTowerActionPayload(this, unit)));
		}
		return true;
	}
	return false;
};


const std::string Tower::selectionMessage() const  {
	std::string res;
	res += "\n" + fieldObjectName() + " health points: " + std::to_string(_startingHealth) + "/" + std::to_string(_health);
	return res;
}