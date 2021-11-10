// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RunnerPlayerController.generated.h"

UCLASS()
class RUNNER_API ARunnerPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	UPROPERTY()
	class APlayerBase* PlayerBase;
	
// Movement variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement", meta = (AllowPrivateAccess = "true"))
	int PathCount = 3;
	// Size of all paths together
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement", meta = (AllowPrivateAccess = "true"))	
	float TrackSize = 800;

	TArray<FVector> Paths;
	int CurrentPath;

	
// Methods	
	virtual void BeginPlay() override;
	// Calculate path's size and location
	void CalculatePaths();
	void MovePlayerToMiddlePath();
	virtual void SetupInputComponent() override;
	void MoveLeft();
	void MoveRight();
};
