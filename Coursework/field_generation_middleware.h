#pragma once

#include "flux_cpp.h"
#include "action_types.h"
#include "Position.h"
#include "movement_validation.h"
#include "unit_store.h"

/**
* @brief Create field
*
*/
class FieldGenerationMiddleware final : public flux_cpp::Middleware {
public:
	static FieldGenerationMiddleware* instance() {
		static FieldGenerationMiddleware* self = new FieldGenerationMiddleware();
		return self;
	}

	/**
	* Triggers actions for generating fields and generating neutral objects
	*/
	std::shared_ptr<flux_cpp::Action> process(const std::shared_ptr<flux_cpp::Action>& action) override {
		auto actionType = action->getType<GameFlowActionTypes>();

		switch (actionType) {
		case GameFlowActionTypes::GameStarted:
		{
			auto payload = action->getPayload<GameStartedActionPayload>();
			auto lands = generateLands(payload.generationSeed, payload.fieldWidth, payload.fieldHeight);
			auto field = new Field(payload.fieldWidth, payload.fieldHeight, lands);
			DISPATCH(new FieldGeneratedAction(field));

			auto fieldObjects = generateFieldObjects(field, payload.generationSeed);
			DISPATCH(new FieldObjectsGeneratedAction(fieldObjects));
			break;
		}
		}

		return action;
	}
private:
	FieldGenerationMiddleware() = default;
};