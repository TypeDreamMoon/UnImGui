// copyright DreamMoon

#pragma once

#include "CoreMinimal.h"
#include "ImGui/Misc/Actor/Public/UnImGuiActor.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UnImguiBlueprintFunctionLibrary.generated.h"

/**
 *
 */
UCLASS(DisplayName="UnImgui蓝图函数库")
class IMGUI_API UUnImguiBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure, DisplayName="获取IMGUIActor", meta=(WorldContext="WorldContextObject"))
	static AUnImGuiActor* GetUnImguiActor(const UObject* WorldContextObject);

	// 支持[error]标红
	UFUNCTION(BlueprintCallable, DisplayName="打印日志", meta=(WorldContext="WorldContextObject"))
	static void PrintLog(const UObject* WorldContextObject, FString Desc);
};
