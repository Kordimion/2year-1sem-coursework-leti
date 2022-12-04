#include "error_store.h"
#include "player_store.h"
#include "unit_store.h"
#include "refresh_middleware.h"
#include "logger_middleware.h"
#include "game_view.h"
#include "game.h"


Game::Game() {
    flux_cpp::Dispatcher::instance().registerMiddleware(LoggerMiddleware::instance());

    flux_cpp::Dispatcher::instance().registerStore(ErrorStore::instance());
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

void Game::run() {
    while (!done) {
        
        while (!wake) {}

        wake = false;
        printGameView();
    };
}

void Game::start() {
    run();
}

