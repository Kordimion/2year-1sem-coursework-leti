#pragma once

#include <mutex>
#include <thread>
#include <atomic>
#include <condition_variable>

class Game
{
private:
	Game();
	~Game();
	void run();
	std::atomic_bool done;
	std::atomic_bool wake = true;
public:
	void start();
	void stop();
	void refresh();
	static Game& instance() {
		static Game self;
		return self;
	}
};
