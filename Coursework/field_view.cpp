#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <chrono>
#include <thread>
#include <cmath>
#include <sstream>

#include "unit_store.h"
#include "field_view.h"

#include "field.h"
#include "field_store.h"
#include "movement_validation.h"
#include "field_object.h"
#include "field_objects_store.h"

std::string generateFieldCharMap(const Field* field, const std::vector<Unit*>& units, const std::vector<FieldObject*> fieldObjects) {
    int height = field->getHeight();
    int width = field->getWidth();
    auto lands = field->getLands();
    
    std::string res = std::string(width * height, ' ');
    
    // lands characters
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            res[y * width + x] = lands[y * width + x]->displayCharacter();
        }
    }

    // unit characters
    for (Unit* a : units) {
        res[a->pos.y * width + a->pos.x] = a->display();
    }

    // FieldObject characters
    for (FieldObject* a : fieldObjects) {
        res[a->pos.y * width + a->pos.x] = a->displayCharacter();
    }

    return res;
}

const int* generateFieldColorMap(const Field* field, const std::vector<Unit*>& units, const std::vector<FieldObject*> fieldObjects) {
    int height = field->getHeight();
    int width = field->getWidth();
    auto lands = field->getLands();

    int* res = new int[height * width];

    // lands colors
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            res[y * width + x] = lands[y * width + x]->displayColor();
        }
    }

    // units colors
    for (Unit* a : units) {
        res[a->pos.y * width + a->pos.x] = 0;
    }

    // FieldObject colors
    for (FieldObject* a : fieldObjects) {
        res[a->pos.y * width + a->pos.x] = a->displayColor();
    }

    // unit movement colors
    if (UnitStore::instance()->isUnitMovementActive()) {
        auto unit = UnitStore::instance()->getSelectedUnit();

        auto movementMap = getIsTileMoveableMap(field, fieldObjects, units);

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                auto pos = Position(x, y);
                bool isReachable = isTileWithinUnitMovementReach(unit, pos);
                bool isMoveable = movementMap[pos];

                if (isMoveable && isReachable) res[y * width + x] = 31;
            }
        }
    }

    // unit selection colors
    if (UnitStore::instance()->isUnitSelectionActive())
    {
        auto pos = UnitStore::instance()->getSelectedUnit()->pos;
        res[pos.y * width + pos.x] = 7;
    }

    // unit selection colors
    if (FieldObjectsStore::instance()->isFieldObjectSelectionActive())
    {
        auto pos = FieldObjectsStore::instance()->getSelectedFieldObject()->pos;
        res[pos.y * width + pos.x] = 7;
    }

    return res;
}

const std::string borderedFieldString(const Field* field, const std::vector<Unit*>& units, const std::vector<FieldObject*> fieldObjects) {
    int height = field->getHeight();
    int width = field->getWidth();

    std::string fieldCharMap = generateFieldCharMap(field, units, fieldObjects);

    char borderCharacter = 'X';
   
    std::string res;
    res += std::string(width + 2, borderCharacter) + '\n'; 

    for (int y = 0; y < height; ++y) {
        res += borderCharacter;

        for (int x = 0; x < width; ++x) {
            res += fieldCharMap[y * width + x];
        }

        res += borderCharacter;
        res += '\n';
    }

    res += std::string(width + 2, borderCharacter) + '\n';

    return res;
}

const void printColoredField(const Field* field, const std::vector<Unit*>& units, const std::vector<FieldObject*> fieldObjects) {
    int height = field->getHeight();
    int width = field->getWidth();

    const auto fieldColorMap = generateFieldColorMap(field, units, fieldObjects);
    const std::string fieldString = borderedFieldString(field, units, fieldObjects);

    int fullHeight = height + 2; // 2 = 2 characters from border
    int fullWidth = width + 3; // 3 = 2 characters from border + 1 from new line

    /*
    for (int y = 0; y < fullHeight; ++y) {
        for (int x = 0; x < fullWidth; ++x) {
            std::cout << fieldString[y * fullWidth + x];
        }
    }
    */

    std::string res;
    
    for (int y = 0; y < fullHeight; ++y) { 
        for (int x = 0; x < fullWidth; ++x) { 
            int colorMapY = y - 1; // 1 = 1 border from top
            int colorMapX = x - 1; // 1 = 1 border from left
            if (colorMapX >= 0 && colorMapX < width && colorMapY >= 0 && colorMapY < height)
            {
                res += "\033[";
                res += std::to_string(fieldColorMap[colorMapY * width + colorMapX]);
                res += "m";
                res += fieldString[y * fullWidth + x];
                res += "\033[0m";
            }
            else
                res += fieldString[y * fullWidth + x];
        }
    }
    std::cout << res;
    delete[] fieldColorMap;
}


std::string getFieldString() {
    return borderedFieldString(FieldStore::instance()->getField(), UnitStore::instance()->getUnits(), FieldObjectsStore::instance()->getFieldObjects());
}

void printFieldView() {
   printColoredField(FieldStore::instance()->getField(), UnitStore::instance()->getUnits(), FieldObjectsStore::instance()->getFieldObjects());
}
