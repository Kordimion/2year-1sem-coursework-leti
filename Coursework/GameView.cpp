#include "GameView.h"
#include "FieldView.h"
#include "UserMenuView.h"
#include "ErrorNotificationView.h"
#include "ErrorStore.h"
#include "UnitStore.h"
#include "UnitSelectionMenuView.h"

#include <Windows.h>
#include <iostream>

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

void printGameView() 
{
    clear();
    if (ErrorStore::instance()->hasError()) {
        printErrorNotification();
    }
    else {
        std::cout << "Strategy game!\n";
        std::cout << "--------------\n";
        printFieldView();
        if (UnitStore::instance()->isUnitSelectionActive())
            printUnitSelectionMenuView();
        else
            printUserMenuView();
    }
}