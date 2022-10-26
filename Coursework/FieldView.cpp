#include "FieldView.h"

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <chrono>
#include <thread>

#include "UnitStore.h";

class Field {
public:
    int height, width;
    const std::string view(const std::vector<Unit*>& units) {
        std::string res;
        for (int i = 0; i < height + 2; ++i) {
            for (int j = 0; j < width + 2; ++j) {
                bool isTopBorder = i == 0;
                bool isBottomBorder = i == height + 1;
                bool isLeftBorder = j == 0;
                bool isRightBorder = j == width + 1;

                bool isBorder = isTopBorder || isBottomBorder || isLeftBorder || isRightBorder;
                if (isBorder) res += 'X';
                else {
                    bool unitDisplayed = false;
                    for (Unit *a : units) {
                        if (a->pos.x == j - 1 && a->pos.y == i - 1) {
                            res += a->display();
                            unitDisplayed = true;
                            break;
                        }
                    }
                    if (!unitDisplayed) res += ' ';
                }
            }
            res += "\n";
        }
        return res;
    }
};

std::string getFieldString() {
    Field field;
    field.height = FIELD_HEIGHT;
    field.width = FIELD_WIDTH;

    const auto units = UnitStore::instance()->getUnits();

    return field.view(units);
}

void printFieldView() {
    std::cout << getFieldString();
}
