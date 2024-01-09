// copyright DreamMoon


#include "ImGui/Misc/Lib/Public/UnImguiBlueprintFunctionLibrary.h"

#include "Kismet/GameplayStatics.h"

AUnImGuiActor* UUnImguiBlueprintFunctionLibrary::GetUnImguiActor(const UObject* WorldContextObject)
{
	AUnImGuiActor* tempActor = Cast<AUnImGuiActor>(UGameplayStatics::GetActorOfClass(WorldContextObject, AUnImGuiActor::StaticClass()));
	if (tempActor)
	{
		return tempActor;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("无法获取UnImGuiActor对象，请检查"));
		return nullptr;
	}
}

void UUnImguiBlueprintFunctionLibrary::PrintLog(const UObject* WorldContextObject, FString Desc)
{
	AUnImGuiActor* Obj = GetUnImguiActor(WorldContextObject);
	if (IsValid(Obj))
	{
		Obj->PrintLog(Desc);
		return;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("UnImguiActorIsNotValid!!!"));
		return;
	}
}
