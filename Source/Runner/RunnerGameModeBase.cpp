// Copyright Epic Games, Inc. All Rights Reserved.


#include "RunnerGameModeBase.h"
#include "Runner/PlatformContent/PlatformContentManager.h"

ARunnerGameModeBase::ARunnerGameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// Setup Components
	PlatformContentManager = CreateDefaultSubobject<UPlatformContentManager>("PlatformContentManager");
}
