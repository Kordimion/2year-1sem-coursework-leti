#pragma once
#include <string>

/**
* @brief To work with location
*
* The position is set according to the Cartesian coordinate axis
*/
struct Position {
public:
	int x, y;

	Position() : x(0), y(0) {}

	Position(int x0,int y0): x(x0),y(y0){}

	Position(const Position& obj) {
		x = obj.x;
		y = obj.y;
	}

	bool operator==(const Position& pos) const {
		return (x == pos.x && y == pos.y);
	}

	bool operator<(const Position& pos) const {
		return y < pos.y || (y == pos.y && x < pos.x);
	}

	int distanceBetween(const Position& pos){
		return abs(pos.x - x) + abs(pos.y - y);
	}

	std::string toString() {
		return std::string("{") + std::to_string(x) + ',' + std::to_string(y) + "}";
	}
};