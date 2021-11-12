// Copyright Epic Games, Inc. All Rights Reserved.


#include "RunnerGameModeBase.h"
#include "Runner/PlatformContent/PlatformContentManager.h"

ARunnerGameModeBase::ARunnerGameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// Setup Components
	PlatformContentManager = CreateDefaultSubobject<UPlatformContentManager>("PlatformContentManager");
}

void ARunnerGameModeBase::GetPaths(TArray<FVector>& PathArray)
{
	CalculatePaths();
	PathArray = Paths;
}

FVector ARunnerGameModeBase::GetRandomPath()
{
	int RandomNum = FMath::RandRange(0, Paths.Num() - 1);
	return Paths[RandomNum];
}

void ARunnerGameModeBase::CalculatePaths()
{
	PathSize = TrackSize / PathCount;
	for(int i = 0; i < PathCount; i++)
	{
		Paths.Add(FVector(0, PathSize / 2 + i * PathSize, 130));
	}
}
