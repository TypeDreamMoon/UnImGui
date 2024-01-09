// copyright DreamMoon


#include "ImGui/Misc/Lib/Public/UnImguiInterface.h"

DEFINE_LOG_CATEGORY(ImguiLog)

// Add default functionality here for any IUnImguiInterface functions that are not pure virtual.
void IUnImguiInterface::SettingDebugMode_Implementation(bool Value)
{
	const FString Str = (Value) ? TEXT("true") : TEXT("false");
	UE_LOG(ImguiLog, Log, TEXT("UnImguiInterface->Setting Debug Mode = %s"), *Str);
}
