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
	
	int num =  Platforms.Num();

	UE_LOG(LogTemp, Warning, TEXT("%d"), num);
}

// Called every frame
void APlatformManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlatformManager::FindPlatforms()
{
	TArray<AActor*> OutActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), PlatformClass, OutActors);
	
	for(AActor* Actor : OutActors)
	{
		APlatformBase* Platform = Cast<APlatformBase>(Actor);
		if(Platform != nullptr)
		{
			Platforms.Add(Platform);
		}
	}
}

