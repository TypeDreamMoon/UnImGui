#pragma once

#include "ImGui/Core/ImGuiCommon.h"
#include "ImOldWindow.generated.h"

UCLASS()
class UWImOldWindow : public UObject
{
	GENERATED_BODY()
public:
	//===============================================//
	//				   	 VALUE						 //
	//===============================================//
	inline static bool imgui_show_demo_window = false;
	inline static bool imgui_show_style_window = false;
	inline static bool imgui_show_log_window = false;
	inline static bool imgui_show_style_edit_window = false;
	inline static bool imgui_show_debug_stack_window = false;
	inline static bool imgui_show_demo_polt_window = false;
	inline static bool imgui_show_debug_stack_bar_window = false;
	inline static bool imgui_show_charactertag_window = false;
	inline static bool imgui_show_debug_stack_string_window = false;
	inline static bool imgui_show_allacotr_window = false;
	inline static bool imgui_show_tagviewer_window = false;

	inline static AActor *imgui_tagviewer_taget_actor = nullptr;

	inline static char imgui_execute_buffer[256] = {};

	inline static int imgui_debug_offset = 0;

	inline static float imgui_fps_max = 60.0f;

	inline static FImGuiTextureHandle imgui_texture_handle;

	enum ContentsType { CT_Text, CT_FillButton };
	inline static ImGuiTableFlags imgui_table_flags = ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg;
	inline static ImGuiTableFlags imgui_static_table_flages = ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersV | ImGuiTableFlags_RowBg | ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable;

	inline static float game_fps = 0.0f;
	inline static TArray<float> game_buffer_fps100 = { 0.0f };

	// FUNCTION

	UFUNCTION(meta=(WorldContext = "WorldContextObject"))
	void Draw(UObject* WorldContextObject, bool& p_open);

	static void HelpMarker(const char* desc);

	bool Show_StyleSelector(const char* label);
	void Show_FontSelector(const char* label);
	void CreatTagView(const AActor* Object);

	void Sparkline(const char* id, const float* values, int count, float min_v, float max_v, int offset, const ImVec4& col, const ImVec2& size);

	UFUNCTION(meta=(WorldContext = "WorldContextObject"))
	void ShowWindow(UObject* WorldContextObject);

	void ShowStyleEditor(ImGuiStyle* ref);
	void ShowDebugStackTable();
	void ShowDebugStackBar();
	void ShowDebugStackString();

	UFUNCTION(meta=(WorldContext = "WorldContextObject"))
	void ShowPlayerTag(UObject* WorldContextObject);

	UFUNCTION(meta=(WorldContext = "WorldContextObject"))
	void ShowAllActor(UObject* WorldContextObject);
	void ShowTagViewer();

};
