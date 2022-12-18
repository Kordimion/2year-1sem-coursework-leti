#include "field_generation.h"

#include "land.h"
#include "water.h"
#include "grass.h"
#include "forest.h"
#include "perlin_noise.h"
#include "field.h"
#include "base.h"
#include "tower.h"
#include "stone_barricade.h"
#include "gold_mine.h"
#include "relic.h"
#include "field_store.h"
#include "field_objects_store.h"
#include "movement_validation.h"

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

template <class T>
void ensureFieldObjectIsCreated(
	std::map<Position, bool>& isTileMoveableMap,  
	const Field* field,
	std::vector<FieldObject*>& fieldObjectVector
) {
	int width = field->getWidth();
	int height = field->getHeight();
	Position pos;
	do {
		pos = Position(rand() % height, rand() % width);
	} while (!isTileMoveableMap[pos]);

	fieldObjectVector.push_back(new T(pos));

	isTileMoveableMap[pos] = false;
}

std::vector<FieldObject*> generateFieldObjects(
	const Field* field,
	unsigned int seed
) {
	const Position basePos(0, 0);
	auto base = new Base(Position(0, 0));
	base->player = PlayerStore::instance()->getCurrentPlayer();

	srand(seed);

	std::vector<FieldObject*> res{ base };

	auto isTileMoveableMap = getIsTileMoveableMap(field, res, UnitStore::instance()->getUnits());

	ensureFieldObjectIsCreated<Tower>(isTileMoveableMap, field, res);
	ensureFieldObjectIsCreated<StoneBarricade>(isTileMoveableMap, field, res);
	ensureFieldObjectIsCreated<GoldMine>(isTileMoveableMap, field, res);
	ensureFieldObjectIsCreated<Relic>(isTileMoveableMap, field, res);
	
	return res;
}

