#pragma once

#include <mutex>
#include <thread>
#include <atomic>
#include <condition_variable>

/**
*@brief Facade, which setups views of an app
*/
class Game{
public:
	void start();

	void stop();

	void refresh();

	static Game& instance() {
		static Game self;
		return self;
	}
private:
	Game();
	~Game();
	void run(unsigned int seed);
	std::atomic_bool done;
	std::atomic_bool wake = true;
};
