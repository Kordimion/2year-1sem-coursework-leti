#pragma once

/**
* @brief To work with location
*
* The position is set according to the Cartesian coordinate axis
*/
struct Position {
public:
	int x, y; //<coordinats

	Position() : x(0), y(0) {}

	Position(int x0,int y0): x(x0),y(y0){}

	Position(const Position& obj) {
		x = obj.x;
		y = obj.y;
	}

	bool operator==(const Position& pos){
		return (x == pos.x && y == pos.y);
	}

	int distanceBetween(const Position& pos){
		int a = pos.x - x;
		int b = pos.y - y;

		a = a > 0 ? a : -a;
		b = b > 0 ? b : -b;

		return a + b;
	}
};