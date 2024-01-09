#include "ImGui/Misc/Window/Public/ImOldWindow.h"

#include "imgui_internal.h"
#include "GameFramework/Character.h"
#include "ImGui/Misc/Window/Public/UnImGuiWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

#define IM_MIN(A, B)            (((A) < (B)) ? (A) : (B))
#define IM_MAX(A, B)            (((A) >= (B)) ? (A) : (B))
#define IM_CLAMP(V, MN, MX)     ((V) < (MN) ? (MN) : (V) > (MX) ? (MX) : (V))

#define IM_STATIC_ASSERT(_COND)         static_assert(_COND, "")

void UWImOldWindow::Draw(UObject* WorldContextObject, bool& p_open)
{
#if WITH_IMGUI

	ShowWindow(WorldContextObject);

	ImGui::Begin(u8"By 梦月", &p_open, ImGuiWindowFlags_MenuBar);
	//-----------------------------------------------------------------------------
	// [Bar] 主窗口导航栏
	//-----------------------------------------------------------------------------
	if (ImGui::BeginMenuBar())
	{
		if (ImGui::BeginMenu(u8"菜单"))
		{
			ImGui::MenuItem(u8"样式编辑器", u8"样式编辑器", &imgui_show_style_edit_window);

			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu(u8"调试"))
		{
			ImGui::MenuItem(u8"调试日志", u8"调试日志", &imgui_show_log_window);
			ImGui::MenuItem(u8"调试堆栈||表", u8"调试堆栈", &imgui_show_debug_stack_window);
			ImGui::MenuItem(u8"调试堆栈||条", u8"调试堆栈", &imgui_show_debug_stack_bar_window);
			ImGui::MenuItem("调试堆栈||字", "调试堆栈", &imgui_show_debug_stack_string_window);
			ImGui::MenuItem("玩家Tag", "PlayerTags", &imgui_show_charactertag_window);
			ImGui::MenuItem("对象查看器", "ObjectViewer", &imgui_show_allacotr_window);
			ImGui::MenuItem("标签查看器", "TagsViewer", &imgui_show_tagviewer_window);

			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu(u8"示例"))
		{
			ImGui::MenuItem(u8"IMGUI DEMO", u8"IMGUI DEMO", &imgui_show_demo_window);
			ImGui::MenuItem(u8"IMGUI PONT DEMO", u8"IMGUI DEMO", &imgui_show_demo_polt_window);

			ImGui::EndMenu();
		}

	ImGui::EndMenuBar();
	}

	//-----------------------------------------------------------------------------
	// [Content] 主窗口内容
	//-----------------------------------------------------------------------------
	// OTHER
	ImGui::Text("工具");
	if (ImGui::Button(u8"样式编辑")) { imgui_show_style_edit_window = !imgui_show_style_edit_window; }
	// if (ImGui::Button("取消Imgui输入")) { UKismetSystemLibrary::ExecuteConsoleCommand(GetWorld(), TEXT("ImGui.ToggleInput")); }

	// DEBUG
	ImGui::Text("调试");
	if (ImGui::Button(u8"调试堆栈")) { imgui_show_debug_stack_window = !imgui_show_debug_stack_window; }
	ImGui::SameLine();
	if (ImGui::Button(u8"调试日志")) { imgui_show_log_window = !imgui_show_log_window; }
	ImGui::SameLine();
	if (ImGui::Button(u8"调试堆栈(条)")) { imgui_show_debug_stack_bar_window = !imgui_show_debug_stack_bar_window; }
	ImGui::SameLine();
	if (ImGui::Button("调试堆栈(字符串)")) { imgui_show_debug_stack_string_window = !imgui_show_debug_stack_string_window; }

	// ImGui::Checkbox("启用调试模式", Cast<USGameInstance>(GetGameInstance())->pGetDebugMode());

	ImGui::Text("数据查看");
	if (ImGui::Button("玩家标签")) { imgui_show_charactertag_window = !imgui_show_charactertag_window; }
	ImGui::SameLine();
	if (ImGui::Button("ALlObject")) { imgui_show_allacotr_window = !imgui_show_allacotr_window; }
	ImGui::SameLine();
	if (ImGui::Button("标签查看器")) { imgui_show_tagviewer_window = !imgui_show_tagviewer_window; }

	ImGui::Text("游戏工具");
	ImGui::InputText("命令", imgui_execute_buffer, IM_ARRAYSIZE(imgui_execute_buffer));
	ImGui::SameLine();
	if (ImGui::Button("执行")) { UKismetSystemLibrary::ExecuteConsoleCommand(GetWorld(), FString(imgui_execute_buffer));}

	// ImGui::Image(imgui_texture_handle, ImVec2(400, 400));


#endif
}

void UWImOldWindow::HelpMarker(const char* desc)
{
	ImGui::TextDisabled(u8"(帮助)");
	if (ImGui::BeginItemTooltip())
	{
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::TextUnformatted(desc);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}

bool UWImOldWindow::Show_StyleSelector(const char* label)
{
	static int style_idx = -1;
	if (ImGui::Combo(label, &style_idx, "Dream\0"))
	{
		switch (style_idx)
		{
		case 0 : ImGuiTool::Imgui_Style_0(); break;

		default: ImGuiTool::Imgui_Style_0(); break;
		}
		return true;
	}
	return false;
}

void UWImOldWindow::Show_FontSelector(const char* label)
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
	ImGui::SameLine();
	HelpMarker(
		"- Load additional fonts with io.Fonts->AddFontFromFileTTF().\n"
		"- The font atlas is built when calling io.Fonts->GetTexDataAsXXXX() or io.Fonts->Build().\n"
		"- Read FAQ and docs/FONTS.md for more details.\n"
		"- If you need to add/remove fonts at runtime (e.g. for DPI change), do it before calling NewFrame().");
}

void UWImOldWindow::CreatTagView(const AActor* Object)
{
#if WITH_IMGUI

	if (ImGui::TreeNode(TCHAR_TO_UTF8(*UKismetSystemLibrary::GetDisplayName(Object))))
	{

		if (ImGui::TreeNode("Info"))
		{
			ImGui::Text("Object Name : %s", TCHAR_TO_UTF8(*UKismetSystemLibrary::GetDisplayName(Object)));

			ImGui::TreePop();
		}

		if (ImGui::TreeNode("Tags"))
		{
			if (Object->Tags.Num() == 0)
			{
				ImGui::Text("无标签");
			}
			else
			{
				for (int i = 0; i < Object->Tags.Num(); i++)
				{
					ImGui::Text("%d  :  ", i);
					ImGui::SameLine();
					ImGui::Text("%s", TCHAR_TO_UTF8(*Object->Tags[i].ToString()));
				}
			}
			ImGui::TreePop();
		}
		ImGui::TreePop();
	}

#endif
}

void UWImOldWindow::Sparkline(
	const char* id,
	const float* values,
	int count,
	float min_v,
	float max_v,
	int offset,
	const ImVec4& col,
	const ImVec2& size
	)
{
	ImPlot::PushStyleVar(ImPlotStyleVar_PlotPadding, ImVec2(0,0));
	if (ImPlot::BeginPlot(id,size,ImPlotFlags_CanvasOnly|ImPlotFlags_NoChild)) {
		ImPlot::SetupAxes(nullptr,nullptr,ImPlotAxisFlags_NoDecorations,ImPlotAxisFlags_NoDecorations);
		ImPlot::SetupAxesLimits(0, count - 1, min_v, max_v, ImGuiCond_Always);
		ImPlot::SetNextLineStyle(col);
		ImPlot::SetNextFillStyle(col, 0.25);
		ImPlot::PlotLine(id, values, count, 1, 0, ImPlotLineFlags_Shaded, offset);
		ImPlot::EndPlot();
	}
	ImPlot::PopStyleVar();
}

void UWImOldWindow::ShowWindow(UObject* WorldContextObject)
{
	if (imgui_show_demo_window)					ImGui::ShowDemoWindow();
	if (imgui_show_style_window)				ImGui::ShowStyleEditor();
	if (imgui_show_log_window)					ImGui::ShowDebugLogWindow(new bool(true));
	if (imgui_show_style_edit_window)			ShowStyleEditor(&ImGui::GetStyle());
	if (imgui_show_debug_stack_window)			ShowDebugStackTable();
	if (imgui_show_demo_polt_window)			ImPlot::ShowDemoWindow();
	if (imgui_show_debug_stack_bar_window)		ShowDebugStackBar();
	if (imgui_show_charactertag_window)			ShowPlayerTag(WorldContextObject);
	if (imgui_show_debug_stack_string_window)	ShowDebugStackString();
	if (imgui_show_allacotr_window)				ShowAllActor(WorldContextObject);
	if (imgui_show_tagviewer_window)			ShowTagViewer();

}

void UWImOldWindow::ShowStyleEditor(ImGuiStyle* ref)
{
#if WITH_IMGUI
	ImGui::Begin(u8"样式编辑器", &imgui_show_style_edit_window);

	ImGuiStyle& style = ImGui::GetStyle();
	static ImGuiStyle ref_saved_style;

	static bool init = true;
	if (init && ref == nullptr)
		ref_saved_style = style;
	init = false;
	if (ref == nullptr)
		ref = &ref_saved_style;

	if (Show_StyleSelector("Colors##Selector"))
	{
		ref_saved_style = style;
	}
	ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.50f);

	Show_FontSelector("Fonts##Selector");

	ImGui::Separator();

	{ bool border = (style.WindowBorderSize > 0.0f); if (ImGui::Checkbox("窗口边界", &border)) { style.WindowBorderSize = border ? 1.0f : 0.0f; } }
	ImGui::SameLine();
	{ bool border = (style.FrameBorderSize > 0.0f);  if (ImGui::Checkbox("帧边界",  &border)) { style.FrameBorderSize  = border ? 1.0f : 0.0f; } }
	ImGui::SameLine();
	{ bool border = (style.PopupBorderSize > 0.0f);  if (ImGui::Checkbox("弹出的边界",  &border)) { style.PopupBorderSize  = border ? 1.0f : 0.0f; } }


	if (ImGui::BeginTabBar("##tabs", ImGuiTabBarFlags_None))
    {
        if (ImGui::BeginTabItem("尺寸"))
        {
            ImGui::SeparatorText("Main");
            ImGui::SliderFloat2("窗口填充", (float*)&style.WindowPadding, 0.0f, 20.0f, "%.0f");
            ImGui::SliderFloat2("框架填充", (float*)&style.FramePadding, 0.0f, 20.0f, "%.0f");
            ImGui::SliderFloat2("单元格填充", (float*)&style.CellPadding, 0.0f, 20.0f, "%.0f");
            ImGui::SliderFloat2("项间距", (float*)&style.ItemSpacing, 0.0f, 20.0f, "%.0f");
            ImGui::SliderFloat2("项目内间距", (float*)&style.ItemInnerSpacing, 0.0f, 20.0f, "%.0f");
            ImGui::SliderFloat2("触摸额外填充", (float*)&style.TouchExtraPadding, 0.0f, 10.0f, "%.0f");
            ImGui::SliderFloat("缩进距离", &style.IndentSpacing, 0.0f, 30.0f, "%.0f");
            ImGui::SliderFloat("滚动条的大小", &style.ScrollbarSize, 1.0f, 20.0f, "%.0f");
            ImGui::SliderFloat("抓取最小尺寸", &style.GrabMinSize, 1.0f, 20.0f, "%.0f");

            ImGui::SeparatorText("Borders");
            ImGui::SliderFloat("窗口边框大小", &style.WindowBorderSize, 0.0f, 1.0f, "%.0f");
            ImGui::SliderFloat("子边框尺寸", &style.ChildBorderSize, 0.0f, 1.0f, "%.0f");
            ImGui::SliderFloat("弹出框边框大小", &style.PopupBorderSize, 0.0f, 1.0f, "%.0f");
            ImGui::SliderFloat("框架边框大小", &style.FrameBorderSize, 0.0f, 1.0f, "%.0f");
            ImGui::SliderFloat("标签边框大小", &style.TabBorderSize, 0.0f, 1.0f, "%.0f");

            ImGui::SeparatorText("Rounding");
            ImGui::SliderFloat("窗口圆角", &style.WindowRounding, 0.0f, 12.0f, "%.0f");
            ImGui::SliderFloat("子圆角", &style.ChildRounding, 0.0f, 12.0f, "%.0f");
            ImGui::SliderFloat("帧圆角", &style.FrameRounding, 0.0f, 12.0f, "%.0f");
            ImGui::SliderFloat("弹出圆角", &style.PopupRounding, 0.0f, 12.0f, "%.0f");
            ImGui::SliderFloat("滚动条圆角", &style.ScrollbarRounding, 0.0f, 12.0f, "%.0f");
            ImGui::SliderFloat("抓住圆角", &style.GrabRounding, 0.0f, 12.0f, "%.0f");
            ImGui::SliderFloat("选项卡圆角", &style.TabRounding, 0.0f, 12.0f, "%.0f");

            ImGui::SeparatorText("Widgets");
            ImGui::SliderFloat2("窗口标题对齐", (float*)&style.WindowTitleAlign, 0.0f, 1.0f, "%.2f");
            int window_menu_button_position = style.WindowMenuButtonPosition + 1;
            if (ImGui::Combo("窗口菜单按钮位置", (int*)&window_menu_button_position, "None\0Left\0Right\0"))
                style.WindowMenuButtonPosition = window_menu_button_position - 1;
            ImGui::Combo("颜色按钮位置", (int*)&style.ColorButtonPosition, "Left\0Right\0");
            ImGui::SliderFloat2("按钮文本对齐", (float*)&style.ButtonTextAlign, 0.0f, 1.0f, "%.2f");
            ImGui::SameLine(); HelpMarker("当按钮大于其文本内容时应用对齐.");
            ImGui::SliderFloat2("可选择文本对齐", (float*)&style.SelectableTextAlign, 0.0f, 1.0f, "%.2f");
            ImGui::SameLine(); HelpMarker("当可选项大于其文本内容时应用对齐.");
            ImGui::SliderFloat("分隔符文本边框大小", &style.SeparatorTextBorderSize, 0.0f, 10.0f, "%.0f");
            ImGui::SliderFloat2("分隔符文本对齐", (float*)&style.SeparatorTextAlign, 0.0f, 1.0f, "%.2f");
            ImGui::SliderFloat2("分隔符文本填充", (float*)&style.SeparatorTextPadding, 0.0f, 40.0f, "%.0f");
            ImGui::SliderFloat("测井滑块填充", &style.LogSliderDeadzone, 0.0f, 12.0f, "%.0f");

            ImGui::SeparatorText("Tooltips");
            for (int n = 0; n < 2; n++)
                if (ImGui::TreeNodeEx(n == 0 ? "HoverFlagsForTooltipMouse" : "HoverFlagsForTooltipNav"))
                {
                    ImGuiHoveredFlags* p = (n == 0) ? &style.HoverFlagsForTooltipMouse : &style.HoverFlagsForTooltipNav;
                    ImGui::CheckboxFlags("ImGuiHoveredFlags_DelayNone", p, ImGuiHoveredFlags_DelayNone);
                    ImGui::CheckboxFlags("ImGuiHoveredFlags_DelayShort", p, ImGuiHoveredFlags_DelayShort);
                    ImGui::CheckboxFlags("ImGuiHoveredFlags_DelayNormal", p, ImGuiHoveredFlags_DelayNormal);
                    ImGui::CheckboxFlags("ImGuiHoveredFlags_Stationary", p, ImGuiHoveredFlags_Stationary);
                    ImGui::CheckboxFlags("ImGuiHoveredFlags_NoSharedDelay", p, ImGuiHoveredFlags_NoSharedDelay);
                    ImGui::TreePop();
                }

            ImGui::SeparatorText("Misc");
            ImGui::SliderFloat2("显示安全区域填充", (float*)&style.DisplaySafeAreaPadding, 0.0f, 30.0f, "%.0f"); ImGui::SameLine(); HelpMarker("Adjust if you cannot see the edges of your screen (e.g. on a TV where scaling has not been configured).");

            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("颜色"))
        {
            static int output_dest = 0;
            static bool output_only_modified = true;
            if (ImGui::Button("Export"))
            {
                if (output_dest == 0)
                    ImGui::LogToClipboard();
                else
                    ImGui::LogToTTY();
                ImGui::LogText("ImVec4* colors = ImGui::GetStyle().Colors;" IM_NEWLINE);
                for (int i = 0; i < ImGuiCol_COUNT; i++)
                {
                    const ImVec4& col = style.Colors[i];
                    const char* name = ImGui::GetStyleColorName(i);
                    if (!output_only_modified || memcmp(&col, &ref->Colors[i], sizeof(ImVec4)) != 0)
                        ImGui::LogText("colors[ImGuiCol_%s]%*s= ImVec4(%.2ff, %.2ff, %.2ff, %.2ff);" IM_NEWLINE,
                            name, 23 - (int)strlen(name), "", col.x, col.y, col.z, col.w);
                }
                ImGui::LogFinish();
            }
            ImGui::SameLine(); ImGui::SetNextItemWidth(120); ImGui::Combo("##output_type", &output_dest, "To Clipboard\0To TTY\0");
            ImGui::SameLine(); ImGui::Checkbox("Only Modified Colors", &output_only_modified);

            static ImGuiTextFilter filter;
            filter.Draw("Filter colors", ImGui::GetFontSize() * 16);

            static ImGuiColorEditFlags alpha_flags = 0;
            if (ImGui::RadioButton("Opaque", alpha_flags == ImGuiColorEditFlags_None))             { alpha_flags = ImGuiColorEditFlags_None; } ImGui::SameLine();
            if (ImGui::RadioButton("Alpha",  alpha_flags == ImGuiColorEditFlags_AlphaPreview))     { alpha_flags = ImGuiColorEditFlags_AlphaPreview; } ImGui::SameLine();
            if (ImGui::RadioButton("Both",   alpha_flags == ImGuiColorEditFlags_AlphaPreviewHalf)) { alpha_flags = ImGuiColorEditFlags_AlphaPreviewHalf; } ImGui::SameLine();
            HelpMarker(
                "In the color list:\n"
                "Left-click on color square to open color picker,\n"
                "Right-click to open edit options menu.");

            ImGui::BeginChild("##colors", ImVec2(0, 0), true, ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_AlwaysHorizontalScrollbar | ImGuiWindowFlags_NavFlattened);
            ImGui::PushItemWidth(-160);
            for (int i = 0; i < ImGuiCol_COUNT; i++)
            {
                const char* name = ImGui::GetStyleColorName(i);
                if (!filter.PassFilter(name))
                    continue;
                ImGui::PushID(i);
                ImGui::ColorEdit4("##color", (float*)&style.Colors[i], ImGuiColorEditFlags_AlphaBar | alpha_flags);
                if (memcmp(&style.Colors[i], &ref->Colors[i], sizeof(ImVec4)) != 0)
                {
                    // Tips: in a real user application, you may want to merge and use an icon font into the main font,
                    // so instead of "Save"/"Revert" you'd use icons!
                    // Read the FAQ and docs/FONTS.md about using icon fonts. It's really easy and super convenient!
                    ImGui::SameLine(0.0f, style.ItemInnerSpacing.x); if (ImGui::Button("Save")) { ref->Colors[i] = style.Colors[i]; }
                    ImGui::SameLine(0.0f, style.ItemInnerSpacing.x); if (ImGui::Button("Revert")) { style.Colors[i] = ref->Colors[i]; }
                }
                ImGui::SameLine(0.0f, style.ItemInnerSpacing.x);
                ImGui::TextUnformatted(name);
                ImGui::PopID();
            }
            ImGui::PopItemWidth();
            ImGui::EndChild();

            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("字体"))
        {
            ImGuiIO& io = ImGui::GetIO();
            ImFontAtlas* atlas = io.Fonts;

        	ImGui::SliderFloat(u8"字体大小", &ImGui::GetFont()->Scale, 0.1f, 5.0f, "%.1f");

        	ImGui::ShowFontAtlas(atlas);

            // Post-baking font scaling. Note that this is NOT the nice way of scaling fonts, read below.
            // (we enforce hard clamping manually as by default DragFloat/SliderFloat allows CTRL+Click text to get out of bounds).
            const float MIN_SCALE = 0.3f;
            const float MAX_SCALE = 2.0f;
            HelpMarker(
                "Those are old settings provided for convenience.\n"
                "However, the _correct_ way of scaling your UI is currently to reload your font at the designed size, "
                "rebuild the font atlas, and call style.ScaleAllSizes() on a reference ImGuiStyle structure.\n"
                "Using those settings here will give you poor quality results.");
            static float window_scale = 1.0f;
            ImGui::PushItemWidth(ImGui::GetFontSize() * 8);
            if (ImGui::DragFloat("window scale", &window_scale, 0.005f, MIN_SCALE, MAX_SCALE, "%.2f", ImGuiSliderFlags_AlwaysClamp)) // Scale only this window
                ImGui::SetWindowFontScale(window_scale);
            ImGui::DragFloat("global scale", &io.FontGlobalScale, 0.005f, MIN_SCALE, MAX_SCALE, "%.2f", ImGuiSliderFlags_AlwaysClamp); // Scale everything
            ImGui::PopItemWidth();

            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("Rendering"))
        {
            ImGui::Checkbox("Anti-aliased lines", &style.AntiAliasedLines);
            ImGui::SameLine();
            HelpMarker("When disabling anti-aliasing lines, you'll probably want to disable borders in your style as well.");

            ImGui::Checkbox("Anti-aliased lines use texture", &style.AntiAliasedLinesUseTex);
            ImGui::SameLine();
            HelpMarker("Faster lines using texture data. Require backend to render with bilinear filtering (not point/nearest filtering).");

            ImGui::Checkbox("Anti-aliased fill", &style.AntiAliasedFill);
            ImGui::PushItemWidth(ImGui::GetFontSize() * 8);
            ImGui::DragFloat("Curve Tessellation Tolerance", &style.CurveTessellationTol, 0.02f, 0.10f, 10.0f, "%.2f");
            if (style.CurveTessellationTol < 0.10f) style.CurveTessellationTol = 0.10f;

            // When editing the "Circle Segment Max Error" value, draw a preview of its effect on auto-tessellated circles.
            ImGui::DragFloat("Circle Tessellation Max Error", &style.CircleTessellationMaxError , 0.005f, 0.10f, 5.0f, "%.2f", ImGuiSliderFlags_AlwaysClamp);
            const bool show_samples = ImGui::IsItemActive();
            if (show_samples)
                ImGui::SetNextWindowPos(ImGui::GetCursorScreenPos());
            if (show_samples && ImGui::BeginTooltip())
            {
                ImGui::TextUnformatted("(R = radius, N = number of segments)");
                ImGui::Spacing();
                ImDrawList* draw_list = ImGui::GetWindowDrawList();
                const float min_widget_width = ImGui::CalcTextSize("N: MMM\nR: MMM").x;
                for (int n = 0; n < 8; n++)
                {
                    const float RAD_MIN = 5.0f;
                    const float RAD_MAX = 70.0f;
                    const float rad = RAD_MIN + (RAD_MAX - RAD_MIN) * (float)n / (8.0f - 1.0f);

                    ImGui::BeginGroup();

                    ImGui::Text("R: %.f\nN: %d", rad, draw_list->_CalcCircleAutoSegmentCount(rad));

                    const float canvas_width = IM_MAX(min_widget_width, rad * 2.0f);
                    const float offset_x     = floorf(canvas_width * 0.5f);
                    const float offset_y     = floorf(RAD_MAX);

                    const ImVec2 p1 = ImGui::GetCursorScreenPos();
                    draw_list->AddCircle(ImVec2(p1.x + offset_x, p1.y + offset_y), rad, ImGui::GetColorU32(ImGuiCol_Text));
                    ImGui::Dummy(ImVec2(canvas_width, RAD_MAX * 2));

                    /*
                    const ImVec2 p2 = ImGui::GetCursorScreenPos();
                    draw_list->AddCircleFilled(ImVec2(p2.x + offset_x, p2.y + offset_y), rad, ImGui::GetColorU32(ImGuiCol_Text));
                    ImGui::Dummy(ImVec2(canvas_width, RAD_MAX * 2));
                    */

                    ImGui::EndGroup();
                    ImGui::SameLine();
                }
                ImGui::EndTooltip();
            }
            ImGui::SameLine();
            HelpMarker("When drawing circle primitives with \"num_segments == 0\" tesselation will be calculated automatically.");

            ImGui::DragFloat("Global Alpha", &style.Alpha, 0.005f, 0.20f, 1.0f, "%.2f"); // Not exposing zero here so user doesn't "lose" the UI (zero alpha clips all widgets). But application code could have a toggle to switch between zero and non-zero.
            ImGui::DragFloat("Disabled Alpha", &style.DisabledAlpha, 0.005f, 0.0f, 1.0f, "%.2f"); ImGui::SameLine(); HelpMarker("Additional alpha multiplier for disabled items (multiply over current value of Alpha).");
            ImGui::PopItemWidth();

            ImGui::EndTabItem();
        }

        ImGui::EndTabBar();
    }

	ImGui::PopItemWidth();

	ImGui::End();
#endif
}

void UWImOldWindow::ShowDebugStackTable()
{
#if WITH_IMGUI
	if (ImGui::Begin(u8"调试堆栈", new bool(true)))
	{
		ImGui::Text(u8"data");
		ImGui::End();
	}
#endif
}

void UWImOldWindow::ShowDebugStackBar()
{
#if WITH_IMGUI
	if (ImGui::Begin(u8"调试堆栈(条)", new bool(true)))
	{
		ImGui::Text(u8"data");
		ImGui::End();
	}
#endif
}

void UWImOldWindow::ShowDebugStackString()
{
	if (ImGui::Begin(u8"调试堆栈(字符串)", new bool(true)))
	{
		ImGui::Text(u8"data");
		ImGui::End();
	}
}

void UWImOldWindow::ShowPlayerTag(UObject* WorldContextObject)
{

#if WITH_IMGUI
	ImGui::Begin("玩家Tags");
	ACharacter* Character = UGameplayStatics::GetPlayerCharacter(WorldContextObject, 0);
	if (Character)
	{
		TArray<FName> Data = Character->Tags;
		if (Data.Num() == 0)
		{
			ImGui::Text("ERROR !!! TAGS == 0 !!!");
		}
		else
		{
			for (int i = 0; i < Data.Num(); ++i)
			{
				ImGui::Text("%d : %s", i, TCHAR_TO_UTF8(*Data[i].ToString()));
			}
		}
	}
	else
	{
		ImGui::Text("ERROR !!! CHARACTER IS NOT VALID !!!");
	}
	ImGui::End();
#endif
}

void UWImOldWindow::ShowAllActor(UObject* WorldContextObject)
{
#if WITH_IMGUI
	TArray<AActor*> ActorBuffer;
	UGameplayStatics::GetAllActorsOfClass(WorldContextObject, AActor::StaticClass(), ActorBuffer);

	if (ActorBuffer.Num() == 0)
	{
		ImGui::Begin("对象窗口");
		ImGui::Text("NULL");
		ImGui::End();
	}
	else
	{
		ImGui::Begin("对象窗口");

		if (ImGui::BeginTable("ActorTable", 3, imgui_static_table_flages))
		{
			ImGui::TableSetupColumn("Index");
			ImGui::TableSetupColumn("ObjectName");
			ImGui::TableHeadersRow();

			for (int row = 0; row < ActorBuffer.Num(); row++)
			{
				ImGui::TableNextRow(); // 下一行
				for (int column = 0; column < 2; column++)
				{
					ImGui::TableSetColumnIndex(column); // 设置格子
					if (column == 0)
					{
						ImGui::Text("%d", row);
					}
					else if (column == 1)
					{
						ImGui::Text("%s", TCHAR_TO_UTF8(*UKismetSystemLibrary::GetDisplayName(ActorBuffer[row])));
					}
					else
					{
						ImGui::Text("Error");
					}
				}
			}
			ImGui::EndTable();
		}
		ImGui::End();
	}
#endif
}

void UWImOldWindow::ShowTagViewer()
{
#if WITH_IMGUI
	TArray<AActor*> ActorBuffer;
	UGameplayStatics::GetAllActorsOfClass(GEngine->GetWorld(), AActor::StaticClass(), ActorBuffer);
	ImGui::Begin("标签查看器");
	for (int i = 0; i < ActorBuffer.Num(); i++)
	{
		CreatTagView(ActorBuffer[i]);

	}
	ImGui::End();
#endif
}

