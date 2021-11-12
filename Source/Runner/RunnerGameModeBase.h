// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RunnerGameModeBase.generated.h"

class UPlatformContentManager;

UCLASS()
class RUNNER_API ARunnerGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ARunnerGameModeBase(const FObjectInitializer& ObjectInitializer);
	UPlatformContentManager* GetContentManager() { return PlatformContentManager; }
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UPlatformContentManager* PlatformContentManager;
};
