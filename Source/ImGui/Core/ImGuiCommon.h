#pragma once

#ifdef IMGUI_API
#define WITH_IMGUI 1
#else
#define WITH_IMGUI 0
#endif // IMGUI_API

#if WITH_IMGUI
#include <ImGui/Core/Public/ImGuiModule.h>
#include <ImGui/Core/Public/ImGuiDelegates.h>

// IMGUI
#include <imgui.h>
// IMPLOT
#include "implot.h"
#endif // WITH_IMGUI
