#include "ImGui/Tools/Public/UnImGuiTool.h"
#include "imgui_internal.h"
#include "Kismet/KismetMathLibrary.h"

FColor ImGuiTool::ImVec4ToFColor(ImVec4 color)
{
	FColor Temp;
	Temp.R = UKismetMathLibrary::Lerp(0, 255, color.x);
	Temp.G = UKismetMathLibrary::Lerp(0, 255, color.y);
	Temp.B = UKismetMathLibrary::Lerp(0, 255, color.z);
	Temp.A = UKismetMathLibrary::Lerp(0, 255, color.w);
	return Temp;
}

FString ImGuiTool::pCharToFString(char* pChar)
{
	//FString MyFString = FString(UTF8_TO_TCHAR(MyCharPtr));
	return FString(UTF8_TO_TCHAR(pChar));
}

FLinearColor ImGuiTool::ImVec4ToFLinearColor(ImVec4 color)
{
	FLinearColor Temp;
	Temp.R = color.x;
	Temp.G = color.y;
	Temp.B = color.z;
	Temp.A = color.w;
	return Temp;
}

ImVec4 ImGuiTool::FColorToImVec4(FColor color)
{
	ImVec4 Temp;
	Temp.x = UKismetMathLibrary::NormalizeToRange(color.R, 0, 255);
	Temp.y = UKismetMathLibrary::NormalizeToRange(color.G, 0, 255);
	Temp.z = UKismetMathLibrary::NormalizeToRange(color.B, 0, 255);
	Temp.w = UKismetMathLibrary::NormalizeToRange(color.A, 0, 255);

	return Temp;
}

char* ImGuiTool::FStringTopChar(FString string)
{
	//char* MyCharPtr = TCHAR_TO_UTF8(*MyFString);
	return TCHAR_TO_UTF8(*string);
}

ImVec4 ImGuiTool::FLinearColorToImVec4(FLinearColor color)
{
	ImVec4 Temp;
	Temp.x = color.R;
	Temp.y = color.G;
	Temp.z = color.B;
	Temp.w = color.A;
	return Temp;
}


void ImGuiTool::Imgui_Style_0()
{
	ImGuiIO IO = ImGui::GetIO();

	ImGuiStyle* pStyle = &ImGui::GetStyle();
	ImVec4* colors = pStyle->Colors;

	// COLOR //

	colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.03f, 0.03f, 0.03f, 0.8f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
	colors[ImGuiCol_Border] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.16f, 0.29f, 0.48f, 0.54f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.02f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.16f, 0.29f, 0.48f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.24f, 0.52f, 0.88f, 1.00f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	colors[ImGuiCol_Button] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.26f, 0.59f, 0.98f, 0.31f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	colors[ImGuiCol_Separator] = colors[ImGuiCol_Border];
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.10f, 0.40f, 0.75f, 0.78f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.10f, 0.40f, 0.75f, 1.00f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.59f, 0.98f, 0.20f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
	colors[ImGuiCol_Tab] = ImLerp(colors[ImGuiCol_Header], colors[ImGuiCol_TitleBgActive], 0.80f);
	colors[ImGuiCol_TabHovered] = colors[ImGuiCol_HeaderHovered];
	colors[ImGuiCol_TabActive] = ImLerp(colors[ImGuiCol_HeaderActive], colors[ImGuiCol_TitleBgActive], 0.60f);
	colors[ImGuiCol_TabUnfocused] = ImLerp(colors[ImGuiCol_Tab], colors[ImGuiCol_TitleBg], 0.80f);
	colors[ImGuiCol_TabUnfocusedActive] = ImLerp(colors[ImGuiCol_TabActive], colors[ImGuiCol_TitleBg], 0.40f);
	colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
	colors[ImGuiCol_TableHeaderBg] = ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
	colors[ImGuiCol_TableBorderStrong] = ImVec4(0.31f, 0.31f, 0.35f, 1.00f); // Prefer using Alpha=1.0 here
	colors[ImGuiCol_TableBorderLight] = ImVec4(0.23f, 0.23f, 0.25f, 1.00f); // Prefer using Alpha=1.0 here
	colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
	colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
	colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
	colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);

	// MAIN //
	pStyle->FrameRounding = 7.0f;
	pStyle->WindowPadding = ImVec2(12.0f, 12.0f);
	pStyle->FramePadding = ImVec2(16.0f, 3.0f);
	pStyle->CellPadding = ImVec2(10.0f, 10.0f);
	pStyle->ItemInnerSpacing = ImVec2(8.0f, 4.0f);
	pStyle->TouchExtraPadding = ImVec2(0.0f, 0.0f);
	pStyle->IndentSpacing = 30.0f;
	pStyle->ScrollbarSize = 14.0f;
	pStyle->GrabMinSize = 8.0f;

	// BORDERS //
	pStyle->WindowBorderSize = 1.0f;
	pStyle->ChildBorderSize = 1.0f;
	pStyle->PopupBorderSize = 1.0f;
	pStyle->FrameBorderSize = 0.0f;
	pStyle->TabBorderSize = 0.0f;

	// ROUNDING //
	pStyle->WindowRounding = 0.0f;
	pStyle->ChildRounding = 0.0f;
	pStyle->FrameRounding = 0.0f;
	pStyle->PopupRounding = 0.0f;
	pStyle->ScrollbarRounding = 0.0f;
	pStyle->GrabRounding = 0.0f;
	pStyle->TabRounding = 0.0f;

	// WIDGETS //
	pStyle->WindowTitleAlign = ImVec2(0.9f, 0.5f);
	pStyle->WindowMenuButtonPosition = ImGuiDir_Left;
	pStyle->ColorButtonPosition = ImGuiDir_Left;
	pStyle->ButtonTextAlign = ImVec2(0.5f, 0.0f);
	pStyle->SelectableTextAlign = ImVec2(0.0f, 0.0f);
	pStyle->SeparatorTextBorderSize = 4.0f;
	pStyle->SeparatorTextAlign = ImVec2(0.5f, 0.5f);
	pStyle->SeparatorTextPadding = ImVec2(8.0f, 8.0f);
	pStyle->LogSliderDeadzone = 5.0f;

	GImGuiTableFlags = ImGuiTableFlags_RowBg | ImGuiTableFlags_Borders | ImGuiTableFlags_BordersH |
		ImGuiTableFlags_BordersOuterH | ImGuiTableFlags_BordersInnerH | ImGuiTableFlags_BordersV |
		ImGuiTableFlags_BordersInnerV | ImGuiTableFlags_BordersInnerV | ImGuiTableFlags_BordersOuter |
		ImGuiTableFlags_BordersInner;
}

#include "ImGui/Core/Public/imgui_spectrum.h"

void ImGuiTool::Imgui_Style_Adobe()
{
	using namespace ImGui;
	ImGuiStyle* style = &ImGui::GetStyle();
	style->GrabRounding = 4.0f;

	ImVec4* colors = style->Colors;
	colors[ImGuiCol_Text] = ColorConvertU32ToFloat4(Spectrum::GRAY800); // text on hovered controls is gray900
	colors[ImGuiCol_TextDisabled] = ColorConvertU32ToFloat4(Spectrum::GRAY500);
	colors[ImGuiCol_WindowBg] = ColorConvertU32ToFloat4(Spectrum::GRAY100);
	colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_PopupBg] = ColorConvertU32ToFloat4(Spectrum::GRAY50);
	// not sure about this. Note: applies to tooltips too.
	colors[ImGuiCol_Border] = ColorConvertU32ToFloat4(Spectrum::GRAY300);
	colors[ImGuiCol_BorderShadow] = ColorConvertU32ToFloat4(Spectrum::Static::NONE); // We don't want shadows. Ever.
	colors[ImGuiCol_FrameBg] = ColorConvertU32ToFloat4(Spectrum::GRAY75);
	// this isnt right, spectrum does not do this, but it's a good fallback
	colors[ImGuiCol_FrameBgHovered] = ColorConvertU32ToFloat4(Spectrum::GRAY50);
	colors[ImGuiCol_FrameBgActive] = ColorConvertU32ToFloat4(Spectrum::GRAY200);
	colors[ImGuiCol_TitleBg] = ColorConvertU32ToFloat4(Spectrum::GRAY300);
	// those titlebar values are totally made up, spectrum does not have this.
	colors[ImGuiCol_TitleBgActive] = ColorConvertU32ToFloat4(Spectrum::GRAY200);
	colors[ImGuiCol_TitleBgCollapsed] = ColorConvertU32ToFloat4(Spectrum::GRAY400);
	colors[ImGuiCol_MenuBarBg] = ColorConvertU32ToFloat4(Spectrum::GRAY100);
	colors[ImGuiCol_ScrollbarBg] = ColorConvertU32ToFloat4(Spectrum::GRAY100); // same as regular background
	colors[ImGuiCol_ScrollbarGrab] = ColorConvertU32ToFloat4(Spectrum::GRAY400);
	colors[ImGuiCol_ScrollbarGrabHovered] = ColorConvertU32ToFloat4(Spectrum::GRAY600);
	colors[ImGuiCol_ScrollbarGrabActive] = ColorConvertU32ToFloat4(Spectrum::GRAY700);
	colors[ImGuiCol_CheckMark] = ColorConvertU32ToFloat4(Spectrum::BLUE500);
	colors[ImGuiCol_SliderGrab] = ColorConvertU32ToFloat4(Spectrum::GRAY700);
	colors[ImGuiCol_SliderGrabActive] = ColorConvertU32ToFloat4(Spectrum::GRAY800);
	colors[ImGuiCol_Button] = ColorConvertU32ToFloat4(Spectrum::GRAY75);
	// match default button to Spectrum's 'Action Button'.
	colors[ImGuiCol_ButtonHovered] = ColorConvertU32ToFloat4(Spectrum::GRAY50);
	colors[ImGuiCol_ButtonActive] = ColorConvertU32ToFloat4(Spectrum::GRAY200);
	colors[ImGuiCol_Header] = ColorConvertU32ToFloat4(Spectrum::BLUE400);
	colors[ImGuiCol_HeaderHovered] = ColorConvertU32ToFloat4(Spectrum::BLUE500);
	colors[ImGuiCol_HeaderActive] = ColorConvertU32ToFloat4(Spectrum::BLUE600);
	colors[ImGuiCol_Separator] = ColorConvertU32ToFloat4(Spectrum::GRAY400);
	colors[ImGuiCol_SeparatorHovered] = ColorConvertU32ToFloat4(Spectrum::GRAY600);
	colors[ImGuiCol_SeparatorActive] = ColorConvertU32ToFloat4(Spectrum::GRAY700);
	colors[ImGuiCol_ResizeGrip] = ColorConvertU32ToFloat4(Spectrum::GRAY400);
	colors[ImGuiCol_ResizeGripHovered] = ColorConvertU32ToFloat4(Spectrum::GRAY600);
	colors[ImGuiCol_ResizeGripActive] = ColorConvertU32ToFloat4(Spectrum::GRAY700);
	colors[ImGuiCol_PlotLines] = ColorConvertU32ToFloat4(Spectrum::BLUE400);
	colors[ImGuiCol_PlotLinesHovered] = ColorConvertU32ToFloat4(Spectrum::BLUE600);
	colors[ImGuiCol_PlotHistogram] = ColorConvertU32ToFloat4(Spectrum::BLUE400);
	colors[ImGuiCol_PlotHistogramHovered] = ColorConvertU32ToFloat4(Spectrum::BLUE600);
	colors[ImGuiCol_TextSelectedBg] = ColorConvertU32ToFloat4((Spectrum::BLUE400 & 0x00FFFFFF) | 0x33000000);
	colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
	colors[ImGuiCol_NavHighlight] = ColorConvertU32ToFloat4((Spectrum::GRAY900 & 0x00FFFFFF) | 0x0A000000);
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
	colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
	colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.20f, 0.20f, 0.20f, 0.35f);
}

void ImGuiTool::Imgui_Style_Enemymouse()
{
	ImGuiStyle& style = ImGui::GetStyle();
	style.Alpha = 1.0;
	style.WindowRounding = 3;
	style.GrabRounding = 1;
	style.GrabMinSize = 20;
	style.FrameRounding = 3;


	style.Colors[ImGuiCol_Text] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.00f, 0.40f, 0.41f, 1.00f);
	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_Border] = ImVec4(0.00f, 1.00f, 1.00f, 0.65f);
	style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_FrameBg] = ImVec4(0.44f, 0.80f, 0.80f, 0.18f);
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.44f, 0.80f, 0.80f, 0.27f);
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.44f, 0.81f, 0.86f, 0.66f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.14f, 0.18f, 0.21f, 0.73f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.54f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.00f, 1.00f, 1.00f, 0.27f);
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.20f);
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.22f, 0.29f, 0.30f, 0.71f);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.00f, 1.00f, 1.00f, 0.44f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.00f, 1.00f, 1.00f, 0.74f);
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_CheckMark] = ImVec4(0.00f, 1.00f, 1.00f, 0.68f);
	style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.00f, 1.00f, 1.00f, 0.36f);
	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.00f, 1.00f, 1.00f, 0.76f);
	style.Colors[ImGuiCol_Button] = ImVec4(0.00f, 0.65f, 0.65f, 0.46f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.01f, 1.00f, 1.00f, 0.43f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.00f, 1.00f, 1.00f, 0.62f);
	style.Colors[ImGuiCol_Header] = ImVec4(0.00f, 1.00f, 1.00f, 0.33f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.00f, 1.00f, 1.00f, 0.42f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.00f, 1.00f, 1.00f, 0.54f);
	style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 1.00f, 1.00f, 0.54f);
	style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.00f, 1.00f, 1.00f, 0.74f);
	style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_PlotLines] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.00f, 1.00f, 1.00f, 0.22f);
}

void ImGuiTool::Imgui_Style_Dougblinks()
{
	ImGuiStyle& style = ImGui::GetStyle();

	// light style from Pacôme Danhiez (user itamago) https://github.com/ocornut/imgui/pull/511#issuecomment-175719267
	style.Alpha = 1.0f;
	style.FrameRounding = 3.0f;
	style.Colors[ImGuiCol_Text] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.94f, 0.94f, 0.94f, 0.94f);
	//style.Colors[ImGuiCol_ChildWindowBg]         = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_PopupBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.94f);
	style.Colors[ImGuiCol_Border] = ImVec4(0.00f, 0.00f, 0.00f, 0.39f);
	style.Colors[ImGuiCol_BorderShadow] = ImVec4(1.00f, 1.00f, 1.00f, 0.10f);
	style.Colors[ImGuiCol_FrameBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.94f);
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.96f, 0.96f, 0.96f, 1.00f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 1.00f, 1.00f, 0.51f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.82f, 0.82f, 0.82f, 1.00f);
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.86f, 0.86f, 0.86f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.98f, 0.98f, 0.98f, 0.53f);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.69f, 0.69f, 0.69f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.59f, 0.59f, 0.59f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.49f, 0.49f, 0.49f, 1.00f);
	//style.Colors[ImGuiCol_ComboBg]               = ImVec4(0.86f, 0.86f, 0.86f, 0.99f);
	style.Colors[ImGuiCol_CheckMark] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.24f, 0.52f, 0.88f, 1.00f);
	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	style.Colors[ImGuiCol_Button] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
	style.Colors[ImGuiCol_Header] = ImVec4(0.26f, 0.59f, 0.98f, 0.31f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	//style.Colors[ImGuiCol_Column]                = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
	//style.Colors[ImGuiCol_ColumnHovered]         = ImVec4(0.26f, 0.59f, 0.98f, 0.78f);
	//style.Colors[ImGuiCol_ColumnActive]          = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	style.Colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 1.00f, 1.00f, 0.50f);
	style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
	style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
	//tyle.Colors[ImGuiCol_CloseButton]           = ImVec4(0.59f, 0.59f, 0.59f, 0.50f);
	//style.Colors[ImGuiCol_CloseButtonHovered]    = ImVec4(0.98f, 0.39f, 0.36f, 1.00f);
	//style.Colors[ImGuiCol_CloseButtonActive]     = ImVec4(0.98f, 0.39f, 0.36f, 1.00f);
	style.Colors[ImGuiCol_PlotLines] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
	style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
	//style.Colors[ImGuiCol_ModalWindowDarkening]  = ImVec4(0.20f, 0.20f, 0.20f, 0.35f);

	if (true)
	{
		for (int i = 0; i <= ImGuiCol_COUNT; i++)
		{
			ImVec4& col = style.Colors[i];
			float H, S, V;
			ImGui::ColorConvertRGBtoHSV(col.x, col.y, col.z, H, S, V);

			if (S < 0.1f)
			{
				V = 1.0f - V;
			}
			ImGui::ColorConvertHSVtoRGB(H, S, V, col.x, col.y, col.z);
			if (col.w < 1.00f)
			{
				col.w *= 1;
			}
		}
	}
	else
	{
		for (int i = 0; i <= ImGuiCol_COUNT; i++)
		{
			ImVec4& col = style.Colors[i];
			if (col.w < 1.00f)
			{
				col.x *= 1;
				col.y *= 1;
				col.z *= 1;
				col.w *= 1;
			}
		}
	}
}

ImGuiTableFlags ImGuiTool::GetImGuiTableFlags()
{
	return GImGuiTableFlags;
}
