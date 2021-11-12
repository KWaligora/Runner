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
	void GetPaths(TArray<FVector>& PathsArray);
	float GetPathSize() { return PathSize; }
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UPlatformContentManager* PlatformContentManager;
	
// Paths options
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement", meta = (AllowPrivateAccess = "true"))
	int PathCount = 3;
	// Size of all paths together
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement", meta = (AllowPrivateAccess = "true"))	
	float TrackSize = 800;

	TArray<FVector> Paths;
	float PathSize;

	// Calculate path's size and location
	void CalculatePaths();
};
