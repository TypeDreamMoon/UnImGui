#pragma once

#include "ImGui/Core/ImGuiCommon.h"
#include "ImGui/Core/Public/imgui_toggle.h"
#include "ImGui/Tools/Public/UnImGuiTool.h"

namespace ImGuiWidgetLib
{
	inline static ImGuiToggleConfig GToggleConfig = ImGuiToggleConfig();

	void mainBar();

	bool StyleSelector(const char* label);
	bool ToggleStyleSelector(const char*label);
	void FontSelector(const char* label);
	template <typename T>
	void IsValidPtrWid(T Type, const char* Desc)
	{
		ImGui::Text("%s : ", Desc);
		ImGui::SameLine();
		if (ImGuiTool::IsValidPtr(Type))
		{
			ImGui::Text("not null");
		}
		else
		{
			ImGui::Text("null");
		}
	}
	void IsValidPtrWid(bool Type, const char* Desc);

	ImGuiToggleConfig* GetToggleConfig();
	void SetToggleConfig(ImGuiToggleConfig config);

	namespace Plot
	{
		void Sparkline(const char* id, const float* value, int count, float min_v, float max_v, int offset, const ImVec4& color, const ImVec2& size);
	}
}
