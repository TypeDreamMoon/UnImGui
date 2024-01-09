#include "ImGui/Misc/Window/Public/UnImGuiWindow.h"

#include "imgui_internal.h"
#include "ImGui/Misc/Lib/Public/UnImguiInterface.h"
#include "ImGui/Misc/Window/Public/UnImGuiWidget.h"
#include "ImGui/Misc/Window/Public/ImConsole.h"
#include "ImGui/Misc/Window/Public/ImOldWindow.h"

#define IM_MIN(A, B)            (((A) < (B)) ? (A) : (B))
#define IM_MAX(A, B)            (((A) >= (B)) ? (A) : (B))
#define IM_CLAMP(V, MN, MX)     ((V) < (MN) ? (MN) : (V) > (MX) ? (MX) : (V))

#define IM_STATIC_ASSERT(_COND)         static_assert(_COND, "")


void ImGuiWindowLib::StyleEditor(bool* p_open)
{
	if (ImGui::Begin("调试窗口样式编辑器", p_open))
	{
		ImGuiStyle& Style = ImGui::GetStyle();
		static ImGuiStyle Ref_SaveStyle;

		// 主题选择器
		ImGui::Text(u8"主题");
		if (ImGuiWidgetLib::StyleSelector(u8"Style##Selector"))
		{
			Ref_SaveStyle = Style;
		}
		ImGuiWidgetLib::ToggleStyleSelector("Style##Toggle");
		ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.80f);

		// 字体选择器
		ImGuiWidgetLib::FontSelector(u8"Font##Selector");

		ImGui::Separator();

		{
			bool border = (Style.WindowBorderSize > 0.0f);
			if (ImGui::Checkbox("窗口边界", &border)) { Style.WindowBorderSize = border ? 1.0f : 0.0f; }
		}
		ImGui::SameLine();
		{
			bool border = (Style.FrameBorderSize > 0.0f);
			if (ImGui::Checkbox("帧边界", &border)) { Style.FrameBorderSize = border ? 1.0f : 0.0f; }
		}
		ImGui::SameLine();
		{
			bool border = (Style.PopupBorderSize > 0.0f);
			if (ImGui::Checkbox("弹出的边界", &border)) { Style.PopupBorderSize = border ? 1.0f : 0.0f; }
		}

		ImGui::Separator();

		if (ImGui::BeginTabBar("##tabs", ImGuiTabBarFlags_None))
		{
			if (ImGui::BeginTabItem("尺寸"))
			{
				ImGui::SeparatorText("Main");
				ImGui::SliderFloat2("窗口填充", (float*)&Style.WindowPadding, 0.0f, 20.0f, "%.0f");
				ImGui::SliderFloat2("框架填充", (float*)&Style.FramePadding, 0.0f, 20.0f, "%.0f");
				ImGui::SliderFloat2("单元格填充", (float*)&Style.CellPadding, 0.0f, 20.0f, "%.0f");
				ImGui::SliderFloat2("项间距", (float*)&Style.ItemSpacing, 0.0f, 20.0f, "%.0f");
				ImGui::SliderFloat2("项目内间距", (float*)&Style.ItemInnerSpacing, 0.0f, 20.0f, "%.0f");
				ImGui::SliderFloat2("触摸额外填充", (float*)&Style.TouchExtraPadding, 0.0f, 10.0f, "%.0f");
				ImGui::SliderFloat("缩进距离", &Style.IndentSpacing, 0.0f, 30.0f, "%.0f");
				ImGui::SliderFloat("滚动条的大小", &Style.ScrollbarSize, 1.0f, 20.0f, "%.0f");
				ImGui::SliderFloat("抓取最小尺寸", &Style.GrabMinSize, 1.0f, 20.0f, "%.0f");

				ImGui::SeparatorText("Borders");
				ImGui::SliderFloat("窗口边框大小", &Style.WindowBorderSize, 0.0f, 1.0f, "%.0f");
				ImGui::SliderFloat("子边框尺寸", &Style.ChildBorderSize, 0.0f, 1.0f, "%.0f");
				ImGui::SliderFloat("弹出框边框大小", &Style.PopupBorderSize, 0.0f, 1.0f, "%.0f");
				ImGui::SliderFloat("框架边框大小", &Style.FrameBorderSize, 0.0f, 1.0f, "%.0f");
				ImGui::SliderFloat("标签边框大小", &Style.TabBorderSize, 0.0f, 1.0f, "%.0f");

				ImGui::SeparatorText("Rounding");
				ImGui::SliderFloat("窗口圆角", &Style.WindowRounding, 0.0f, 12.0f, "%.0f");
				ImGui::SliderFloat("子圆角", &Style.ChildRounding, 0.0f, 12.0f, "%.0f");
				ImGui::SliderFloat("帧圆角", &Style.FrameRounding, 0.0f, 12.0f, "%.0f");
				ImGui::SliderFloat("弹出圆角", &Style.PopupRounding, 0.0f, 12.0f, "%.0f");
				ImGui::SliderFloat("滚动条圆角", &Style.ScrollbarRounding, 0.0f, 12.0f, "%.0f");
				ImGui::SliderFloat("抓住圆角", &Style.GrabRounding, 0.0f, 12.0f, "%.0f");
				ImGui::SliderFloat("选项卡圆角", &Style.TabRounding, 0.0f, 12.0f, "%.0f");

				ImGui::SeparatorText("Widgets");
				ImGui::SliderFloat2("窗口标题对齐", (float*)&Style.WindowTitleAlign, 0.0f, 1.0f, "%.2f");
				int window_menu_button_position = Style.WindowMenuButtonPosition + 1;
				if (ImGui::Combo("窗口菜单按钮位置", (int*)&window_menu_button_position, "None\0Left\0Right\0"))
					Style.WindowMenuButtonPosition = window_menu_button_position - 1;
				ImGui::Combo("颜色按钮位置", (int*)&Style.ColorButtonPosition, "Left\0Right\0");
				ImGui::SliderFloat2("按钮文本对齐", (float*)&Style.ButtonTextAlign, 0.0f, 1.0f, "%.2f");
				ImGui::SliderFloat2("可选择文本对齐", (float*)&Style.SelectableTextAlign, 0.0f, 1.0f, "%.2f");
				ImGui::SliderFloat("分隔符文本边框大小", &Style.SeparatorTextBorderSize, 0.0f, 10.0f, "%.0f");
				ImGui::SliderFloat2("分隔符文本对齐", (float*)&Style.SeparatorTextAlign, 0.0f, 1.0f, "%.2f");
				ImGui::SliderFloat2("分隔符文本填充", (float*)&Style.SeparatorTextPadding, 0.0f, 40.0f, "%.0f");
				ImGui::SliderFloat("测井滑块填充", &Style.LogSliderDeadzone, 0.0f, 12.0f, "%.0f");

				ImGui::SeparatorText("Tooltips");
				for (int n = 0; n < 2; n++)
					if (ImGui::TreeNodeEx(n == 0 ? "HoverFlagsForTooltipMouse" : "HoverFlagsForTooltipNav"))
					{
						ImGuiHoveredFlags* p = (n == 0)
							                       ? &Style.HoverFlagsForTooltipMouse
							                       : &Style.HoverFlagsForTooltipNav;
						ImGui::CheckboxFlags("ImGuiHoveredFlags_DelayNone", p, ImGuiHoveredFlags_DelayNone);
						ImGui::CheckboxFlags("ImGuiHoveredFlags_DelayShort", p, ImGuiHoveredFlags_DelayShort);
						ImGui::CheckboxFlags("ImGuiHoveredFlags_DelayNormal", p, ImGuiHoveredFlags_DelayNormal);
						ImGui::CheckboxFlags("ImGuiHoveredFlags_Stationary", p, ImGuiHoveredFlags_Stationary);
						ImGui::CheckboxFlags("ImGuiHoveredFlags_NoSharedDelay", p, ImGuiHoveredFlags_NoSharedDelay);
						ImGui::TreePop();
					}

				ImGui::SeparatorText("Misc");
				ImGui::SliderFloat2("显示安全区域填充", (float*)&Style.DisplaySafeAreaPadding, 0.0f, 30.0f, "%.0f");
				ImGui::SameLine();

				ImGui::EndTabItem();
			}

			if (ImGui::BeginTabItem("颜色"))
			{
				// static int output_dest = 0;
				// static bool output_only_modified = true;
				// if (ImGui::Button("Export"))
				// {
				//     if (output_dest == 0)
				//         ImGui::LogToClipboard();
				//     else
				//         ImGui::LogToTTY();
				//     ImGui::LogText("ImVec4* colors = ImGui::GetStyle().Colors;" IM_NEWLINE);
				//     for (int i = 0; i < ImGuiCol_COUNT; i++)
				//     {
				//         const ImVec4& col = style.Colors[i];
				//         const char* name = ImGui::GetStyleColorName(i);
				//         if (!output_only_modified || memcmp(&col, &ref->Colors[i], sizeof(ImVec4)) != 0)
				//             ImGui::LogText("colors[ImGuiCol_%s]%*s= ImVec4(%.2ff, %.2ff, %.2ff, %.2ff);" IM_NEWLINE,
				//                 name, 23 - (int)strlen(name), "", col.x, col.y, col.z, col.w);
				//     }
				//     ImGui::LogFinish();
				// }
				// ImGui::SameLine(); ImGui::SetNextItemWidth(120); ImGui::Combo("##output_type", &output_dest, "To Clipboard\0To TTY\0");
				// ImGui::SameLine(); ImGui::Checkbox("Only Modified Colors", &output_only_modified);

				// static ImGuiTextFilter filter;
				// filter.Draw("Filter colors", ImGui::GetFontSize() * 16);

				static ImGuiColorEditFlags alpha_flags = 0;
				if (ImGui::RadioButton("Opaque", alpha_flags == ImGuiColorEditFlags_None))
				{
					alpha_flags = ImGuiColorEditFlags_None;
				}
				ImGui::SameLine();
				if (ImGui::RadioButton("Alpha", alpha_flags == ImGuiColorEditFlags_AlphaPreview))
				{
					alpha_flags = ImGuiColorEditFlags_AlphaPreview;
				}
				ImGui::SameLine();
				if (ImGui::RadioButton("Both", alpha_flags == ImGuiColorEditFlags_AlphaPreviewHalf))
				{
					alpha_flags = ImGuiColorEditFlags_AlphaPreviewHalf;
				}
				ImGui::SameLine();

				ImGui::BeginChild("##colors", ImVec2(0, 0), true,
				                  ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_AlwaysHorizontalScrollbar
				                  | ImGuiWindowFlags_NavFlattened);
				ImGui::PushItemWidth(-160);
				for (int i = 0; i < ImGuiCol_COUNT; i++)
				{
					const char* name = ImGui::GetStyleColorName(i);
					// if (!filter.PassFilter(name))
					//     continue;
					ImGui::PushID(i);
					ImGui::ColorEdit4("##color", (float*)&Style.Colors[i], ImGuiColorEditFlags_AlphaBar | alpha_flags);
					if (memcmp(&Style.Colors[i], &Ref_SaveStyle.Colors[i], sizeof(ImVec4)) != 0)
					{
						// Tips: in a real user application, you may want to merge and use an icon font into the main font,
						// so instead of "Save"/"Revert" you'd use icons!
						// Read the FAQ and docs/FONTS.md about using icon fonts. It's really easy and super convenient!
						ImGui::SameLine(0.0f, Style.ItemInnerSpacing.x);
						if (ImGui::Button("Save")) { Ref_SaveStyle.Colors[i] = Style.Colors[i]; }
						ImGui::SameLine(0.0f, Style.ItemInnerSpacing.x);
						if (ImGui::Button("Revert")) { Style.Colors[i] = Ref_SaveStyle.Colors[i]; }
					}
					ImGui::SameLine(0.0f, Style.ItemInnerSpacing.x);
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

				static float window_scale = 1.0f;
				ImGui::PushItemWidth(ImGui::GetFontSize() * 8);
				if (ImGui::DragFloat("window scale", &window_scale, 0.005f, MIN_SCALE, MAX_SCALE, "%.2f",
				                     ImGuiSliderFlags_AlwaysClamp)) // Scale only this window
					ImGui::SetWindowFontScale(window_scale);
				ImGui::DragFloat("global scale", &io.FontGlobalScale, 0.005f, MIN_SCALE, MAX_SCALE, "%.2f",
				                 ImGuiSliderFlags_AlwaysClamp); // Scale everything
				ImGui::PopItemWidth();

				ImGui::EndTabItem();
			}

			if (ImGui::BeginTabItem("Rendering"))
			{
				ImGui::Checkbox("Anti-aliased lines", &Style.AntiAliasedLines);
				ImGui::SameLine();

				ImGui::Checkbox("Anti-aliased lines use texture", &Style.AntiAliasedLinesUseTex);
				ImGui::SameLine();

				ImGui::Checkbox("Anti-aliased fill", &Style.AntiAliasedFill);
				ImGui::PushItemWidth(ImGui::GetFontSize() * 8);
				ImGui::DragFloat("Curve Tessellation Tolerance", &Style.CurveTessellationTol, 0.02f, 0.10f, 10.0f,
				                 "%.2f");
				if (Style.CurveTessellationTol < 0.10f) Style.CurveTessellationTol = 0.10f;

				// When editing the "Circle Segment Max Error" value, draw a preview of its effect on auto-tessellated circles.
				ImGui::DragFloat("Circle Tessellation Max Error", &Style.CircleTessellationMaxError, 0.005f, 0.10f,
				                 5.0f, "%.2f", ImGuiSliderFlags_AlwaysClamp);
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
						const float offset_x = floorf(canvas_width * 0.5f);
						const float offset_y = floorf(RAD_MAX);

						const ImVec2 p1 = ImGui::GetCursorScreenPos();
						draw_list->AddCircle(ImVec2(p1.x + offset_x, p1.y + offset_y), rad,
						                     ImGui::GetColorU32(ImGuiCol_Text));
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

				ImGui::DragFloat("Global Alpha", &Style.Alpha, 0.005f, 0.20f, 1.0f, "%.2f");
				// Not exposing zero here so user doesn't "lose" the UI (zero alpha clips all widgets). But application code could have a toggle to switch between zero and non-zero.
				ImGui::DragFloat("Disabled Alpha", &Style.DisabledAlpha, 0.005f, 0.0f, 1.0f, "%.2f");
				ImGui::SameLine();
				ImGui::PopItemWidth();

				ImGui::EndTabItem();
			}

			ImGui::EndTabBar();
		}


		ImGui::End();
	}
}

void ImGuiWindowLib::DebugValue(bool* p_open)
{
	if (ImGui::Begin(GDebugValueWindowName, p_open))
	{
		ImGui::Text("Global Value Debug");
		ImGui::Separator();

		ImGui::Text("GWindowHanld Is Valid : ");
		ImGui::SameLine();
		if (&GWindowHandle == nullptr)
			ImGui::Text("null");
		else ImGui::Text("not null");

		ImGui::Text("GWindowHanld->Console Is Valid : ");
		ImGui::SameLine();
		if (GWindowHandle.Console == nullptr)
			ImGui::Text("null");
		else ImGui::Text("not null");

		// if (GWindowHandle.MainWindow != nullptr)
		// {
		// 	if (GWindowHandle.MainWindow->InterfaceObject != nullptr)
		// 	{
		// 		// FString interfaceobj = GWindowHandle.MainWindow->InterfaceObject->GetName();
		// 		// FString interfaceobjtemp = FString("MainWindow->InterfaceObject name : ");
		// 		// interfaceobjtemp.Append(interfaceobj);
		// 		// // ImGuiWidgetLib::IsValidPtrWid(GWindowHandle.MainWindow->InterfaceObject, TCHAR_TO_UTF8(*interfaceobjtemp));
		// 		// // UUnImguiInterface* Interface = Cast<UUnImguiInterface>(GWindowHandle.MainWindow->InterfaceObject);
		// 		// ImGuiWidgetLib::IsValidPtrWid(Interface, "MainWindow->InterfaceObject->Cast<UUImguiInterface>");
		// 	}
		// }

		ImGui::End();
	}
}

void ImGuiWindowLib::showStyleEditor(bool* p_open)
{
	StyleEditor(p_open);
}

void ImGuiWindowLib::showConsole(bool* p_open)
{
	// static ImConsole console;
	// GWindowHandle.Console = &console;
	GetWindowHandle()->Console->Draw("SCO::Console", p_open);
}

void ImGuiWindowLib::showDebugValue(bool* p_open)
{
	DebugValue(p_open);
}

void ImGuiWindowLib::showOldWindow(bool* p_open)
{
	static UWImOldWindow Wobj = UWImOldWindow();
	GetWindowHandle()->OldWindow = &Wobj;
	Wobj.Draw(GEngine->GetWorld(), *p_open);
}

void ImGuiWindowLib::showMainWindow(bool* p_open)
{
	static WImMainWindow Wobj = WImMainWindow();
	GetWindowHandle()->MainWindow = &Wobj;
	Wobj.Draw(p_open);
}

void ImGuiWindowLib::Draw()
{
	static ImConsole Console = ImConsole();
	GetWindowHandle()->Console = &Console;
	if (GShowStyleEditor) { showStyleEditor(&GShowStyleEditor); }
	if (GShowConsole) { showConsole(&GShowConsole); }
	if (GShowDebugValue) { showDebugValue(&GShowDebugValue); }
	if (GShowMainWindow) { showMainWindow(&GShowMainWindow); }

	// if(GShowOldWindow)		{ showOldWindow(&GShowOldWindow); }
}

void ImGuiWindowLib::closeAllWindow()
{
	GShowConsole = false;
	GShowDebugValue = false;
	GShowMainWindow = false;
	GShowPropertyWatcher = false;
	GShowStyleEditor = false;
}

FUnImguiWindowHandle* ImGuiWindowLib::GetWindowHandle()
{
	return &GWindowHandle;
}
