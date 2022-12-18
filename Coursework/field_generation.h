#pragma once
#include "land.h"
#include "field_object.h"
#include "field.h"
#include "field_store.h"
#include <vector>

Land** generateLands(unsigned int seed, int width, int height);

std::vector<FieldObject*> generateFieldObjects(
	const Field* field,
	unsigned int seed
);