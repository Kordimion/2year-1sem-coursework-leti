#pragma once

#include "console_helpers.h"
#include <windows.h>
#include "game.h"
#include "views.h"

void gotoxy(int x, int y) {
	COORD pos = { (short int)x, (short int)y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

void copyField() {
	std::string s = getFieldString();

	OpenClipboard(0);
	EmptyClipboard();
	HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, s.size());
	if (!hg) {
		CloseClipboard();
		return;
	}
	memcpy(GlobalLock(hg), s.c_str(), s.size());
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT, hg);
	CloseClipboard();
	GlobalFree(hg);

	Game::instance().refresh();
}
