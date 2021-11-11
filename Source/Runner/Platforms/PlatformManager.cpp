// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformManager.h"

#include "Kismet/GameplayStatics.h"
#include "Runner/Platforms/PlatformBase.h"

// Sets default values
APlatformManager::APlatformManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlatformManager::BeginPlay()
{
	Super::BeginPlay();

	FindPlatforms();
	InitLevel();
}

// Called every frame
void APlatformManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Get all platforms from scene to array
void APlatformManager::FindPlatforms()
{
	TArray<AActor*> OutActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), PlatformClass, OutActors);
	
	for(AActor* Actor : OutActors)
	{
		APlatformBase* Platform = Cast<APlatformBase>(Actor);
		if(Platform != nullptr)
		{
			FreePlatforms.Add(Platform);
		}
	}
}

// Spawn first 3 platforms
void APlatformManager::InitLevel()
{
	for(int i = 0; i < 3; i++)
	{
		FreePlatforms[i]->SetActorLocation(FVector(i*2200, 400, 0));
		OccupiedPlatforms.Add(FreePlatforms[i]);
	}
	for(int i = 0; i < 3; i++)
	{
		FreePlatforms.RemoveAt(i);
		OccupiedPlatforms[i]->SetMovement(PlatformSpeed, true);
	}
}

void APlatformManager::SpawnPlatform()
{
	
}

