// copyright DreamMoon

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UnImguiInterface.generated.h"
DECLARE_LOG_CATEGORY_EXTERN(ImguiLog, Log, All)

// This class does not need to be modified.
UINTERFACE(MinimalAPI,meta=(DisplayName = "UnImgui接口"))
class UUnImguiInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 *
 */
class IMGUI_API IUnImguiInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "IMGUI INTERFACE")
	void SettingDebugMode(bool Value);
	virtual void SettingDebugMode_Implementation(bool Value);
};
