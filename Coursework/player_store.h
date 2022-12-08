#pragma once

#include "flux_cpp.h"
#include "action_types.h"
#include "player.h"

#include <vector>

/**
* @brief Store for players managment
*/
class PlayerStore final : public flux_cpp::Store {
public:
	static PlayerStore* instance() {
		static PlayerStore* self = new PlayerStore();
		return self;
	}

	Player* getCurrentPlayer() {
		return players[currentPlayerId];
	}

	void process(const std::shared_ptr<flux_cpp::Action>& action) override {}
private:
	std::vector<Player*> players; //< All of players
	int currentPlayerId; //< Id of active player 

	PlayerStore() : currentPlayerId(0) {
		players.push_back(new Player);
	}
};