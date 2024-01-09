#pragma once
#include "ImConsole.h"
#include "ImMainWindow.h"
#include "ImOldWindow.h"

struct FUnImguiWindowHandle
{
	FUnImguiWindowHandle();

	ImConsole* Console;
	UWImOldWindow* OldWindow;
	WImMainWindow* MainWindow;
};
