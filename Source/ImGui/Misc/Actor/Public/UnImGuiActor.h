// copyright DreamMoon

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// IMGUI INCLUDE
#include "ImGui/Core/ImGuiCommon.h"
#include "ImGui/Misc/Window/Public/UnImGuiWindow.h"
#include "ImGui/Misc/Window/Public/UnImGuiWidget.h"

#include "UnImGuiActor.generated.h"

UCLASS()
class IMGUI_API AUnImGuiActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AUnImGuiActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	// 是否渲染IMGUI
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="是否渲染IMGUI")
	bool bIsRender;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName="是否启用输入")
	bool bIsEnabledInput;

	// IMGUI Texture Handle
	FImGuiTextureHandle TextureHandle;
	FUnImguiWindowHandle* pWindowHandle;

public:
	// IMGUI MAIN FUNCTION

	// 显示窗口
	UFUNCTION(BlueprintCallable, DisplayName="显示IMGUI窗口")
	virtual void DisplayImGuiWindow(bool bIsRenderWindow);

	UFUNCTION(BlueprintCallable, DisplayName="启用IMGUI输入")
	virtual void SetInputEnabled(bool bEnabled);

	virtual void IMGUI_Begin();
	virtual void IMGUI_Tick();
	virtual void IMGUI_Game_Tick();
	virtual void IMGUI_EndPlay();

	//支持[error]标红
	UFUNCTION(BlueprintCallable, DisplayName="打印日志")
	virtual void PrintLog(FString Desc);

	UPROPERTY(EditAnywhere, DisplayName="消息发送对象")
	TSubclassOf<UObject> InterfaceObject = nullptr;
	// 向 DEBUG VALUE 窗口添加一个可视化表
	// Name: 窗口名称
	// value: 数值
	// barMin: 条最小值
	// barMax: 条最大值
	// count: 条分割数
	// barSize: 条大小
	UFUNCTION(BlueprintCallable, DisplayName="调试数值")
	void DebugValue_Bar(FName Name, float value, int count, bool bBackground, FVector2D barSize = FVector2D(-1, 50), FLinearColor Color = FLinearColor(1, 1, 1, 1));
};
