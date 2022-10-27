#include "Game.h"
#include "GameView.h"

#include "flux_cpp.h"
#include "RefreshMiddleware.h"
#include "ErrorStore.h"
#include "PlayerStore.h"
#include "UnitStore.h"

Game::Game() {
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

