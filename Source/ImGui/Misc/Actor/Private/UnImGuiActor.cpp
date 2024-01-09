// copyright DreamMoon


#include "ImGui/Misc/Actor/Public/UnImGuiActor.h"

#include "ImGui/Tools/Public/UnImGuiTool.h"

#include "Misc/FileHelper.h"
#include "Kismet/GameplayStatics.h"
#include "ImGui/Misc/PropertyWatcher/Public/PropertyWatcher.h"

// Sets default values
AUnImGuiActor::AUnImGuiActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUnImGuiActor::BeginPlay()
{
	Super::BeginPlay();


}

void AUnImGuiActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

// Called every frame
void AUnImGuiActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bIsRender)
	{
		IMGUI_Game_Tick();
	}
}

//================================================================
// [MAIN] IMGUI MAIN FUNCTION
//================================================================

void AUnImGuiActor::IMGUI_Begin()
{
#if WITH_IMGUI

#endif
}

void AUnImGuiActor::IMGUI_Tick()
{
#if WITH_IMGUI
	ImGuiWindowLib::Draw();
	ImGuiWidgetLib::mainBar();
	if (ImGuiWindowLib::GShowPropertyWatcher)
	{
		// This should be set to true once at the beginning.
		// It's not crucial to set it, but among other things it clears the internal actors array after a restart.
		// If you looked up some actors in the actors tab and didn't clear them after a restart you will get a crash.
		// This happens because internally we use static TArray<> which doesn't get cleared on a restart, only on the first compile.
		bool PropertyWatcherInit = false;

		static TArray<PropertyWatcher::MemberPath> WatchedMembers;

		auto World = GetWorld();
		auto GameInstance = GetGameInstance();
		auto GameMode = UGameplayStatics::GetGameMode(GetWorld());
		auto PlayerController = World->GetFirstPlayerController();

		PropertyWatcher::PropertyItemCategory CatA = {
			"Group A", {
				PropertyWatcher::MakeObjectItem(GetWorld()),
				PropertyWatcher::MakeObjectItemNamed(GameInstance, GameInstance->GetClass()->GetName()),

				// You can also add structs like this:
				// PropertyWatcherMakeStructItem(FMyStruct, &MyStruct),
				//
				// That said, the function macro is using StaticStruct<StructType>() to get the script struct, but I
				// couldn't get it to work for built in structs while writing this usage code.
				// But local self made structs should definitely work.
			}
		};

		PropertyWatcher::PropertyItemCategory CatB = {
			"Group B", {
				PropertyWatcher::MakeObjectItem(GameMode),
				PropertyWatcher::MakeObjectItemNamed(PlayerController, PlayerController->GetClass()->GetName()),
			}
		};

		TArray<PropertyWatcher::PropertyItemCategory> Objects = {CatA, CatB};

		bool WantsToSave, WantsToLoad;
		PropertyWatcher::Update("Actors", Objects, WatchedMembers, GetWorld(), &ImGuiWindowLib::GShowPropertyWatcher, &WantsToSave,
		                        &WantsToLoad, PropertyWatcherInit);

		if (PropertyWatcherInit)
			WantsToLoad = true;

		FString WatchWindowFilePath = FPaths::ProjectSavedDir() + "ImGui/PropertyWatcher-WatchWindowMembers.txt";
		if (WantsToSave)
			FFileHelper::SaveStringToFile(PropertyWatcher::ConvertWatchedMembersToString(WatchedMembers),
			                              *WatchWindowFilePath);

		if (WantsToLoad)
		{
			FString Data;
			if (FFileHelper::LoadFileToString(Data, *WatchWindowFilePath))
				PropertyWatcher::LoadWatchedMembersFromString(Data, WatchedMembers);
		}

		PropertyWatcherInit = false;
	}
#endif
}

void AUnImGuiActor::IMGUI_Game_Tick()
{
#if WITH_IMGUI
	if (ImGuiTool::IsValidPtr(ImGuiWindowLib::GetWindowHandle()->MainWindow))
	{
		ImGuiWindowLib::GetWindowHandle()->MainWindow->InterfaceObject = InterfaceObject;
	}
#endif
}

void AUnImGuiActor::IMGUI_EndPlay()
{
#if WITH_IMGUI
#endif
}

void AUnImGuiActor::PrintLog(FString Desc)
{
	if (ImGuiWindowLib::GetWindowHandle()->Console == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("ERROR WindowHandle->Console无访问"));
		return;
	}
	else
	{
		ImGuiWindowLib::GetWindowHandle()->Console->AddLog(ImGuiTool::FStringTopChar(Desc));
	}

}



void AUnImGuiActor::DebugValue_Bar(FName Name, float value, int count, bool bBackground, FVector2D barSize, FLinearColor Color)
{

	static TArray<float>  valueArray = TArray<float>();
	static float value_min = 0;
	static float value_max = 0;

	if (bBackground)
	{
		//数组处理
		int Size = valueArray.Num();
		if (Size< count)
		{
			valueArray.Add(value);
		}
		else
		{
			valueArray.RemoveAt(0);
			valueArray.Add(value);
		}

		value_max = 0;
		value_min = 10000;
		for (int i = 0; i < valueArray.Num(); i++)
		{
			if (valueArray[i] > value_max)
				value_max = valueArray[i];
			if (valueArray[i] < value_min)
				value_min = valueArray[i];
		}
	}

	if (ImGuiWindowLib::GShowDebugValue)
	{
		if (!bBackground)
		{
			//数组处理
			int Size = valueArray.Num();
			if (Size< count)
			{
				valueArray.Add(value);
			}
			else
			{
				valueArray.RemoveAt(0);
				valueArray.Add(value);
			}

			value_max = 0;
			value_min = 10000;
			for (int i = 0; i < valueArray.Num(); i++)
			{
				if (valueArray[i] > value_max)
					value_max = valueArray[i];
				if (valueArray[i] < value_min)
					value_min = valueArray[i];
			}
		}
		// GUI逻辑
#if WITH_IMGUI
		if (ImGui::Begin(ImGuiWindowLib::GetDebubValueWindowName()))
		{
			if (valueArray.IsEmpty())
			{
				ImGui::Text("%s : Array Is Empty", TCHAR_TO_UTF8(*Name.ToString()));
			}
			else
			{
				if (ImGui::BeginTable("##DebugTable", 3 ,ImGuiWindowLib::GTableFlags, ImVec2(-1, 0)))
				{
					ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthFixed, 35.0f);
					ImGui::TableSetupColumn("Value", ImGuiTableColumnFlags_WidthFixed, 50.0f);
					ImGui::TableSetupColumn("Emg");
					ImGui::TableHeadersRow();
					ImPlot::PushColormap(ImPlotColormap_Cool);
					ImGui::TableNextRow();
					ImGui::TableSetColumnIndex(0);
					ImGui::Text("%s", TCHAR_TO_UTF8(*Name.ToString()));
					ImGui::TableSetColumnIndex(1);
					ImGui::Text("%.3f \n min:%.3f \n max:%.3f \n count:%d", value, value_min, value_max, count);
					ImGui::TableSetColumnIndex(2);
					ImGuiWidgetLib::Plot::Sparkline("##Debug", valueArray.GetData(), count, value_min, value_max, 0, ImGuiTool::FLinearColorToImVec4(Color), ImVec2(barSize.X, barSize.Y));

					ImPlot::PopColormap();
					ImGui::EndTable();
				}
			}
			ImGui::End();
		}
#endif
	}
}

void AUnImGuiActor::DisplayImGuiWindow(bool bIsRenderWindow)
{
#if WITH_IMGUI
	bIsRender = bIsRenderWindow;
	if (bIsRenderWindow)
	{
		// RENDER
		IMGUI_Begin();
		FImGuiDelegates::OnWorldDebug().AddUObject(this, &AUnImGuiActor::IMGUI_Tick);
	}
	else
	{
		// NOT RENDER
		IMGUI_EndPlay();
		FImGuiDelegates::OnWorldDebug().RemoveAll(this);
		FImGuiModule::Get().ReleaseTexture(TextureHandle);
		ImGuiWindowLib::closeAllWindow();
	}
#endif
}

void AUnImGuiActor::SetInputEnabled(bool bEnabled)
{
	bIsEnabledInput = bEnabled;
	FImGuiModule::Get().SetInputMode(bEnabled);
}
