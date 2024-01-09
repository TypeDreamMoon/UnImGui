#pragma once

#include "ImGui/Core/ImGuiCommon.h"

// TODO: 该窗口依赖于UnImguiActor

class WImMainWindow
{
public:
	bool bDebugMode;
	UObject* InterfaceObject = nullptr;
	void Draw(bool* p_open);
};
