// Copyright Epic Games, Inc. All Rights Reserved.


#include "RunnerGameModeBase.h"
#include "Runner/PlatformContent/PlatformContentManager.h"

ARunnerGameModeBase::ARunnerGameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// Setup Components
	PlatformContentManager = CreateDefaultSubobject<UPlatformContentManager>("PlatformContentManager");
	
	CalculatePaths();
}

void ARunnerGameModeBase::GetPaths(TArray<FVector>& PathsArray)
{
	PathsArray = Paths;
}

void ARunnerGameModeBase::CalculatePaths()
{
	PathSize = TrackSize / PathCount;
	for(int i = 0; i < PathCount; i++)
	{
		Paths.Add(FVector(0, PathSize / 2 + i * PathSize, 130));
	}
}
