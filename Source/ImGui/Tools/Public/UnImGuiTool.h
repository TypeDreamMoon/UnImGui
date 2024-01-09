#pragma once

#include "ImGui/Core/ImGuiCommon.h"

namespace ImGuiTool
{

	//=======================================================
	//	TO
	//=======================================================

	//IMGUI TO UNREAL

	static FColor ImVec4ToFColor(ImVec4 color);
	static FString pCharToFString(char* pChar);
	static FLinearColor ImVec4ToFLinearColor(ImVec4 color);

	//UNREAL TO IMGUI

	static ImVec4 FColorToImVec4(FColor color);
	static char* FStringTopChar(FString string);
	static ImVec4 FLinearColorToImVec4(FLinearColor color);

	template <typename T>
	// 查询该指针是否为空
	static bool IsValidPtr(T* This)
	{
		if (This != nullptr)
			return true;
		else return false;
	}

	//IMGUI

	static ImGuiTableFlags GImGuiTableFlags;

	void Imgui_Style_0();
	void Imgui_Style_Adobe();
	void Imgui_Style_Enemymouse();
	void Imgui_Style_Dougblinks();
	static ImGuiTableFlags GetImGuiTableFlags();



}
