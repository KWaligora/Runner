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
	class APlayerCharacter* PlayerChar;
	
// Movement variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement", meta = (AllowPrivateAccess = "true"))
	int PathCount = 3;
	// Size of all paths together
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement", meta = (AllowPrivateAccess = "true"))	
	float TrackSize = 800;
	// Result is 1 * PathChangeSpeed, in seconds
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement", meta = (AllowPrivateAccess = "true"))	
	float PathChangeSpeed = 2;
	
	TArray<FVector> Paths;
	int CurrentPath;
	float PathSize;


	
// Methods
	
	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginPlay() override;
	// Calculate path's size and location
	void CalculatePaths();
	void MovePlayerToMiddlePath();
	virtual void SetupInputComponent() override;
	// If player is below 0 height, call OnDeath
	void CheckPlayersHeight();
	void MoveLeft();
	void MoveRight();
	// Interpolate to CurrentPath
	void HandleMovement(float DeltaSeconds);
	void Jump();
};
