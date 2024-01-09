#include "ImGui/Misc/Window/Public/UnImGuiWidget.h"

#include "ImGui/Misc/Window/Public/UnImGuiWindow.h"
#include "ImGui/Tools/Public/UnImGuiTool.h"
#include "ImGui/Core/Public/imgui_toggle_presets.h"
#include "ImGui/Core/Public/imgui_toggle_renderer.h"

void ImGuiWidgetLib::mainBar()
{
	if (ImGui::BeginMainMenuBar())
	{
		ImGui::Text(u8"星之章控制台");
		if (ImGui::BeginMenu(u8"窗口"))
		{
			ImGui::MenuItem("主窗口", NULL, &ImGuiWindowLib::GShowMainWindow);
			ImGui::MenuItem("样式编辑器", NULL, &ImGuiWindowLib::GShowStyleEditor);
			ImGui::MenuItem("控制台", NULL, &ImGuiWindowLib::GShowConsole);
			ImGui::MenuItem("DebugValue", NULL, &ImGuiWindowLib::GShowDebugValue);
			// ImGui::MenuItem("旧版界面", NULL, &ImGuiWindowLib::GShowOldWindow);
			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	}
}

// 样式选择器
bool ImGuiWidgetLib::StyleSelector(const char* label)
{
	const char* itemName[] = { "默认样式" , "ImGui::StyleColorsDark" , "ImGui::StyleColorLight" , "ImGui::StyleColorsClassic" , "Adobe" , "Dougblinks" , "Enemymouse" };
	static int Style_Idx = 0;
	if (ImGui::Combo(label, &Style_Idx, itemName, IM_ARRAYSIZE(itemName)))
	{
		switch (Style_Idx)
		{
		// 这里添加样式选择器可选择的样式函数
		case 0 : ImGuiTool::Imgui_Style_0(); break;
		case 1 : ImGui::StyleColorsDark(); break;
		case 2 : ImGui::StyleColorsLight(); break;
		case 3 : ImGui::StyleColorsClassic(); break;
		case 4 : ImGuiTool::Imgui_Style_Adobe(); break;
		case 5 : ImGuiTool::Imgui_Style_Dougblinks(); break;
		case 6 : ImGuiTool::Imgui_Style_Enemymouse(); break;

		default: ImGuiTool::Imgui_Style_0(); break;
		}
	}
		return true;
}

bool ImGuiWidgetLib::ToggleStyleSelector(const char* label)
{
	const char*  itemName[] = { "默认样式" , "炫光样式" , "材质样式" , "MC样式" , "IOS样式" };
	static int Style_Idx = 0;
	if (ImGui::Combo(label, &Style_Idx, itemName, IM_ARRAYSIZE(itemName)))
	{
		switch (Style_Idx)
		{
			// 这里添加样式选择器可选择的样式函数
		case 0 : SetToggleConfig(ImGuiTogglePresets::DefaultStyle()); break;
		case 1 : SetToggleConfig(ImGuiTogglePresets::GlowingStyle()); break;
		case 2 : SetToggleConfig(ImGuiTogglePresets::MaterialStyle()); break;
		case 3 : SetToggleConfig(ImGuiTogglePresets::MinecraftStyle()); break;
		case 4 : SetToggleConfig(ImGuiTogglePresets::RectangleStyle()); break;
		case 5 : SetToggleConfig(ImGuiTogglePresets::iOSStyle()); break;

		default: SetToggleConfig(ImGuiTogglePresets::DefaultStyle()); break;
		}
	}
	return true;
}

void ImGuiWidgetLib::FontSelector(const char* label)
{
	ImGuiIO& io = ImGui::GetIO();
	const ImFont* font_current = ImGui::GetFont();
	if (ImGui::BeginCombo(label, font_current->GetDebugName()))
	{
		for (int n = 0; n < io.Fonts->Fonts.Size; n++)
		{
			ImFont* font = io.Fonts->Fonts[n];
			ImGui::PushID((void*)font);
			if (ImGui::Selectable(font->GetDebugName(), font == font_current))
				io.FontDefault = font;
			ImGui::PopID();
		}
		ImGui::EndCombo();
	}
}

void ImGuiWidgetLib::IsValidPtrWid(bool Type, const char* Desc)
{
	ImGui::Text("%s : ", Desc);
	ImGui::SameLine();
	if (Type)
	{
		ImGui::Text("not null");
	}
	else
	{
		ImGui::Text("null");
	}
}

ImGuiToggleConfig* ImGuiWidgetLib::GetToggleConfig()
{
	return &GToggleConfig;
}

void ImGuiWidgetLib::SetToggleConfig(ImGuiToggleConfig config)
{
	GToggleConfig = config;
}

void ImGuiWidgetLib::Plot::Sparkline(const char* id, const float* value, int count, float min_v, float max_v,
                                     int offset, const ImVec4& color, const ImVec2& size)
{
	ImPlot::PushStyleVar(ImPlotStyleVar_PlotPadding, ImVec2(0,0));
	if (ImPlot::BeginPlot(id, size, ImPlotFlags_CanvasOnly | ImPlotFlags_NoChild))
	{
		ImPlot::SetupAxes(nullptr,nullptr,ImPlotAxisFlags_NoDecorations,ImPlotAxisFlags_NoDecorations);
		ImPlot::SetupAxesLimits(0, count - 1, min_v, max_v, ImGuiCond_Always);
		ImPlot::SetNextLineStyle(color);
		ImPlot::SetNextFillStyle(color, 0.25);
		ImPlot::PlotLine(id, value, count, 1, 0, ImPlotLineFlags_Shaded, offset);
		ImPlot::EndPlot();
	}
	ImPlot::PopStyleVar();
}


