#include "field_generation.h"

#include "land.h"
#include "water.h"
#include "grass.h"
#include "forest.h"
#include "perlin_noise.h"
#include "field.h"

Land* createLandFromPerlinNoise(const double& noise) {
	if (noise < 0.25) return new Water();
	if (noise < 0.75) return new Grass();
	return new Forest();
}

Land** generateLands(unsigned int seed, int width, int height)
{
	const siv::PerlinNoise perlin{ seed };

	Land** res = new Land * [width * height]{};

	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			double noise = perlin.octave2D_01(x * 0.2, y * 0.2, 4);
			int xBorderCloseness = std::min(x, width - x - 1);
			int yBorderCloseness = std::min(y, height - y - 1);
			if (std::min(xBorderCloseness, yBorderCloseness) < 2) noise += 0.26;
			res[y * width + x] = createLandFromPerlinNoise(noise);
		}
	}

	return res;
}