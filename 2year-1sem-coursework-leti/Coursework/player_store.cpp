#pragma once
#include "action_types.h"
#include "player_store.h"

/**
* @brief Gold waste
*/
void PlayerStore::process(const std::shared_ptr<flux_cpp::Action>& action) {
	switch (action->getType<FieldObjectActionType>()) {
	case FieldObjectActionType::UnitBought: {
		auto payload = action->getPayload<BaseUnitFactorySelectedPayload>();
		payload.base->player->gold -= payload.base->factory->unitCost();
		break;
	}
	}
}

