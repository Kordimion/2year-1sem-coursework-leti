#pragma once
#include <string>

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
		int a = pos.x - x;
		int b = pos.y - y;

		a = abs(a);
		b = abs(b);

		return a + b;
	}

	std::string toString() {
		return std::string("{") + std::to_string(x) + ',' + std::to_string(y) + "}";
	}
};