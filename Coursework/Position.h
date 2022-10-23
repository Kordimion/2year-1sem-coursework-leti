#pragma once
struct Position {
	int x, y;
	Position() : x(0), y(0) {}
	Position(int x0,int y0): x(x0),y(y0){}
	Position(const Position& obj) {
		x = obj.x;
		y = obj.y;
	}
};