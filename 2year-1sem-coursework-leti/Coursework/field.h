#pragma once
#include "land.h"

/**
* @brief Game area
*/
class Field {
public:
	Field(int width, int height, Land** lands) : _height(height), _width(width), _lands(lands) {}
	int getHeight() const { return _height; }
	int getWidth() const { return _width; }
	Land** getLands() const { return _lands; }
private:
	int _height, _width; //< field parameters
	Land** _lands; //< field's inner part
};