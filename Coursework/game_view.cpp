#include <iostream>
#include <Windows.h>

#include "game_view.h"
#include "field_view.h"
#include "user_menu_view.h"
#include "error_notification_view.h"
#include "error_store.h"
#include "unit_store.h"
#include "unit_selection_menu_view.h"
#include "unit_movement_menu_view.h"

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


void printGameView() {
    clear();
    if (ErrorStore::instance()->hasError()) {
        printErrorNotification();
    }
    else {
        std::cout << "Strategy game!\n";
        std::cout << "--------------\n";
        printFieldView();
        if (UnitStore::instance()->isUnitSelectionActive())
            if (UnitStore::instance()->isUnitMovementActive())
                printUnitMovementMenuView();
            else
                printUnitSelectionMenuView();
        else
            printUserMenuView();
    }
}