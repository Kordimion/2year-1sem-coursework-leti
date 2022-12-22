#pragma once

#include "serializable_action.h"

enum class GameFlowActionTypes {
	GameStarted = 1
};

struct GameStartedActionPayload {
	int fieldWidth, fieldHeight;
	unsigned int generationSeed;
	GameStartedActionPayload(unsigned int seed, int width, int height)
		: fieldWidth(width), fieldHeight(height), generationSeed(seed) {}
	std::string Serialize() {
		std::string res = "{";
		res += generationSeed + ",";
		res += fieldWidth + ",";
		res += fieldHeight + "}";
		return res;
	}
};

struct GameStartedAction : public SerializableAction {
	GameStartedAction(GameStartedActionPayload payload) 
		: SerializableAction(GameFlowActionTypes::GameStarted, payload) {}
	const std::string Serialize() const override { 
		return std::string("GameStartedAction|") + 
			getPayload<GameStartedActionPayload>().Serialize(); 
	};
};