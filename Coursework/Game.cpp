#include "error_store.h"
#include "player_store.h"
#include "unit_store.h"
#include "refresh_middleware.h"
#include "game_view.h"
#include "game.h"
#include "perlin_noise.h"
#include "field_store.h"
#include "field_generation.h"
#include "unit_actions_middleware.h"
#include "field_objects_store.h"
#include "field_generation_middleware.h"

Game::Game() {
    flux_cpp::Dispatcher::instance().registerMiddleware(FieldGenerationMiddleware::instance());
    flux_cpp::Dispatcher::instance().registerMiddleware(UnitActionsMiddleware::instance());

    flux_cpp::Dispatcher::instance().registerStore(ErrorStore::instance());
    flux_cpp::Dispatcher::instance().registerStore(FieldStore::instance());
    flux_cpp::Dispatcher::instance().registerStore(FieldObjectsStore::instance());
    flux_cpp::Dispatcher::instance().registerStore(PlayerStore::instance());
    flux_cpp::Dispatcher::instance().registerStore(UnitStore::instance());

    flux_cpp::Dispatcher::instance().registerClosingMiddleware(RefreshMiddleware::instance());
}

Game::~Game() {
    stop();
}

void Game::refresh() {
    wake = true;
    std::this_thread::yield();
}

void Game::stop() {
    wake = true;
    done = true;
}

void Game::run(unsigned int seed) {
    DISPATCH(new GameStartedAction(GameStartedActionPayload(1234, 40, 20)));

    while (!done) {
        
        while (!wake) {}

        wake = false;
        printGameView();
    };
}

void Game::start() {
    run(12345);
}

