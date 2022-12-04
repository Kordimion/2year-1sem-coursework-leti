#pragma once
#include "land.h"

class Field {
public:
	Field(int height, int width, Land** lands) : _height(height), _width(width), _lands(lands) {}
	int getHeight() const { return _height; }
	int getWidth() const { return _width; }
	Land** getLands() const { return _lands; }
private:
	int _height, _width;
	Land** _lands;
};