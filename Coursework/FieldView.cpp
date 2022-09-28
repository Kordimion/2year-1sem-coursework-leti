#include "FieldView.h"
#include "UnitStore.h"
#include "Unit.h"

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <chrono>
#include <thread>

void printFieldView() {
    int height = 10, width = 10;
    for (int i = 0; i < height; ++i) 
    {
        for (int j = 0; j < width; ++j) std::cout << '*';
        
        std::cout << '\n';
    }
}
