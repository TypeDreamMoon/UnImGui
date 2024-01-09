#include "ImGui/Misc/Window/Public/ImMainWindow.h"

#include "ImGui/Core/Public/imgui_toggle.h"
#include "ImGui/Misc/Lib/Public/UnImguiInterface.h"
#include "ImGui/Misc/Window/Public/UnImGuiWidget.h"
#include "ImGui/Misc/Window/Public/UnImGuiWindow.h"

void WImMainWindow::Draw(bool* p_open)
{
	ImGui::SetNextWindowSize(ImVec2(520, 600), ImGuiCond_FirstUseEver);

	if (ImGui::Begin("By --DreamMoon--", p_open, ImGuiWindowFlags_MenuBar))
	{
		//===============================================
		//	[BEGIN] MAIN MENU
		//===============================================
		if (ImGui::BeginMenuBar())
		{
			//====================调试=====================
			if (ImGui::BeginMenu("调试"))
			{
				if(ImGui::MenuItem("启用游戏调试模式", nullptr, bDebugMode))
				{
					bDebugMode = !bDebugMode;
					for (TObjectIterator<UObject> It; It; ++It)
					{
						UObject* Object = *It;
						//bool isImplement = trap->GetClass()->ImplementsInterface(UReactToTriggerInterface::StaticClass())
						bool isImplement = Object->GetClass()->ImplementsInterface(UUnImguiInterface::StaticClass());
						if (isImplement)
						{
							IUnImguiInterface* Interface = Cast<IUnImguiInterface>(Object);
							Interface->Execute_SettingDebugMode(Object, bDebugMode);
						}
					}
				}
				ImGui::EndMenu();
			}


			ImGui::EndMenuBar();
		}


		//===============================================
		//	[BEGIN] WINDOW CONTENT
		//===============================================

		ImGui::Text("调试");
		if (ImGui::Toggle("调试模式", &bDebugMode, *ImGuiWidgetLib::GetToggleConfig()))
		{
			for (TObjectIterator<UObject> It; It; ++It)
			{
				UObject* Object = *It;
				//bool isImplement = trap->GetClass()->ImplementsInterface(UReactToTriggerInterface::StaticClass())
				bool isImplement = Object->GetClass()->ImplementsInterface(UUnImguiInterface::StaticClass());
				if (isImplement)
				{
					IUnImguiInterface* Interface = Cast<IUnImguiInterface>(Object);
					Interface->Execute_SettingDebugMode(Object, bDebugMode);
				}
			}
		}
		ImGui::Toggle("启用数值调试器", &ImGuiWindowLib::GShowPropertyWatcher, *ImGuiWidgetLib::GetToggleConfig());


		ImGui::End();
	}
}
