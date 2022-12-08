#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <chrono>
#include <thread>
#include <cmath>

#include "unit_store.h"
#include "field_view.h"


class Field {
public:
    int height, width; //< field parameters

    /**
    * @brief Constructs the field
    * 
    * Ìakes a field, its borders and places units on it
    * 
    * @param units array of units
    * @return field like a string
    */
    const std::string view(const std::vector<Unit*>& units) {
        std::string res;

        for (int i = 0; i < height + 2; ++i) {
            for (int j = 0; j < width + 2; ++j) {
                bool isTopBorder = i == 0;
                bool isBottomBorder = i == height + 1;
                bool isLeftBorder = j == 0;
                bool isRightBorder = j == width + 1;

                bool isBorder = isTopBorder || isBottomBorder || isLeftBorder || isRightBorder;
                if (isBorder)
                    res += 'X';
                else {
                    bool unitDisplayed = false;
                    for (Unit *a : units) {
                        if (a->pos.x == j - 1 && a->pos.y == i - 1) {
                            res += a->display();
                            unitDisplayed = true;
                            break;
                        }
                    }
                    if (!unitDisplayed)
                        res += '*';
                }
            }
            res += "\n";
        }
        return res;
    }
};

/**
* @brief Run view function
*/
std::string getFieldString() {
    Field field;
    field.height = FIELD_HEIGHT;
    field.width = FIELD_WIDTH;

    const auto units = UnitStore::instance()->getUnits();
    return field.view(units);
}
/**
* @brief Outputs the field to the console
*
* It works in three modes:unit movement, unit selection and standard
*/

void printFieldView() {
    const auto fieldString = getFieldString();

    if (UnitStore::instance()->isUnitMovementActive()) {
        auto pos = UnitStore::instance()->getSelectedUnit()->pos;
        int selectedCalculatedIndex = (pos.x + 1) + (pos.y + 1) * (FIELD_WIDTH + 3);
        int range = UnitStore::instance()->getSelectedUnit()->getStats()->getSpeed();

        for (int i = 0; i < fieldString.length(); i++) {
            auto diffY = abs(i / (FIELD_WIDTH + 3) - (pos.y + 1));
            auto diffX = abs(i % (FIELD_WIDTH + 3) - (pos.x + 1));

            if (diffX + diffY <= range && fieldString[i] != 'X') {
                if (diffX == 0 && diffY == 0)
                    std::cout << "\033[31m" << fieldString[selectedCalculatedIndex] << "\033[0m";
                else
                    std::cout << "\033[33m" << fieldString[i] << "\033[0m";
            }
            else
                std::cout << fieldString[i];
        }
    }
    else if (UnitStore::instance()->isUnitSelectionActive()) {
        auto pos = UnitStore::instance()->getSelectedUnit()->pos;
        int selectedCalculatedIndex = (pos.x+1) + (pos.y + 1) * (FIELD_WIDTH + 3);
        int range = UnitStore::instance()->getSelectedUnit()->getStats()->getRange();
        
        std::cout << fieldString.substr(0, selectedCalculatedIndex);
        std::cout << "\033[31m" << fieldString[selectedCalculatedIndex] << "\033[0m";
        std::cout << fieldString.substr(selectedCalculatedIndex + 1);
    }
    else {
        std::cout << fieldString;
    }
}
