#include "Game.h"
#include <mutex>

using namespace std;

int main() {
    Game::instance().start();
    return 0; /* use Ctrl+C, never returns */
}