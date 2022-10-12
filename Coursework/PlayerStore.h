#pragma once

#include "flux_cpp.h"
#include "ActionTypes.h"
#include "Player.h"
#include <vector>


class PlayerStore final : public flux_cpp::Store {
private:
	PlayerStore() {
		Player* pl = new Player;
}

public:


void process(const std::shared_ptr<flux_cpp::Action>& action) override;

	
};