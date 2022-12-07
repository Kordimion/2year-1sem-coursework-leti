#pragma once

struct GameStartedPayload {
	int width, height;
	unsigned int seed;
	GameStartedPayload(unsigned int _seed, int _width = 30, int _height = 20)
		: width(_width), height(_height), seed(_seed) {};
};