// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformManager.generated.h"

UCLASS()
class RUNNER_API APlatformManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatformManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
// Exposed
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Platforms", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class APlatformBase> PlatformClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platforms", meta = (AllowPrivateAccess = "true"))
	float PlatformSpeed = 500;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platforms", meta = (AllowPrivateAccess = "true"))
	float PlatformsGap = 600;
// non-Exposed	
	TArray<class APlatformBase*> FreePlatforms;
	TArray<class APlatformBase*> OccupiedPlatforms;

	// Get all platforms from scene to array
	void FindPlatforms();
	// Spawn first 3 platforms
	void InitLevel();
	void SpawnPlatform();
};
