#pragma once

#include <memory>
#include <iostream>
#include <Windows.h>

#include "flux_cpp.h"
#include "Game.h"

class RefreshMiddleware final : public flux_cpp::Middleware {
private:
	RefreshMiddleware() = default;
public:
	static RefreshMiddleware* instance() {
		static RefreshMiddleware* self = new RefreshMiddleware();
		return self;
	}

	std::shared_ptr<flux_cpp::Action> process(const std::shared_ptr<flux_cpp::Action>& action) override {
		Game::instance().refresh();
		return action;
	}
};