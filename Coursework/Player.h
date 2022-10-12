#pragma once
 
#include <string>

struct Player {
	std::string name;
	int id;
	Player() {
		name = "Fool";
		id = 0;
	}
};