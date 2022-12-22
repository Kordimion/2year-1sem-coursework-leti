#include <iostream>
#include <Windows.h>

#include "error_store.h"
#include "unit_store.h"
#include "field_store.h"
#include "field_objects_store.h"

#include "views.h"

/**
* @brief Clear the screen
*/
void clear() {
    COORD topLeft = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}

/**
* @brief Print the start screen
*/
void printGameView() {
    clear();
    if (ErrorStore::instance()->hasError()) {
        printErrorNotification();
    }
    else {
        std::cout << "Strategy game!\n";
        std::cout << "--------------\n";
        if (FieldStore::instance()->getField() == nullptr)
            std::cout << "Building field, please wait...";
        else
            printFieldView();

        if (FieldObjectsStore::instance()->isFieldObjectSelectionActive()) {
            printFieldObjectSelectionMenuView();
            return;
        }

        if (UnitStore::instance()->isUnitSelectionActive())
            if (UnitStore::instance()->isUnitMovementActive())
                printUnitMovementMenuView();
            else
                printUnitSelectionMenuView();
        else
            printUserMenuView();
    }
}