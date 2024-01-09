#pragma once

#include "UnImguiWindowHandle.h"
#include "ImGui/Core/ImGuiCommon.h"

namespace ImGuiWindowLib
{
	void StyleEditor(bool* p_open);
	void DebugValue(bool* p_open);

	namespace DebugValueFun
	{
	}

	//
	inline bool GShowStyleEditor = false;
	inline bool GShowConsole = false;
	inline bool GShowDebugValue = false;
	inline bool GShowMainWindow = false;
	inline bool GShowPropertyWatcher = false;
	// inline bool GShowOldWindow;

	// DebugValue Window Name
	inline const char*  GDebugValueWindowName = "DebugValue";

	inline const ImGuiTableFlags GTableFlags = ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersV | ImGuiTableFlags_RowBg | ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable;

	inline FUnImguiWindowHandle GWindowHandle = FUnImguiWindowHandle();

	//
	void showStyleEditor(bool* p_open);
	void showConsole(bool* p_open);
	void showDebugValue(bool* p_open);
	void showOldWindow(bool* p_open);
	void showMainWindow(bool* p_open);

	void Draw();

	inline const char* GetDebubValueWindowName() { return GDebugValueWindowName; }

	void closeAllWindow();

	static FUnImguiWindowHandle* GetWindowHandle();
}
