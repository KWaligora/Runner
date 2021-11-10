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
	FVector CurrentPath = FVector(0,0,120);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement", meta = (AllowPrivateAccess = "true"))
	float PathCount = 3;
	// Size of all paths together
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement", meta = (AllowPrivateAccess = "true"))	
	float TrackSize = 800;

	TArray<FVector> Paths;

	
// Methods	
	virtual void BeginPlay() override;
	void CalculatePaths();
	virtual void SetupInputComponent() override;
};
