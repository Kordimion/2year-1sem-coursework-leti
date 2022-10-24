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
    std::unique_lock lock(mutex);

    wake = true;
    condition.notify_one();
    std::this_thread::yield();
}

void Game::stop() {
    std::unique_lock lock(mutex);

    wake = true;
    done = true;
    condition.notify_one();
}

void Game::run() {
    std::unique_lock lock(mutex);

    while (!done) {
        while (!wake) {
            condition.wait(lock);
        }

        wake = false;
        printGameView();
    };
}

void Game::start() {
    run();
}

