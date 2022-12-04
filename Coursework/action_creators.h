#pragma once

#include "unit_type.h"
#include "position.h"
#include <string>

void dispatchSelectUnitType(UnitType ut);

void dispatchAddUnit(Position position);

void dispatchStartUnitSelection();

void dispatchNotImplemented(std::string message);

void dispatchIncorrectInput(std::string message);

void dispatchFieldGenerated(unsigned int seed, int width, int height);

