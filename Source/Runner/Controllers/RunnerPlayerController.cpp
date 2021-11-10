// Fill out your copyright notice in the Description page of Project Settings.


#include "RunnerPlayerController.h"
#include "Runner/Characters/PlayerBase.h"

void ARunnerPlayerController::BeginPlay()
{
	Super::BeginPlay();

	PlayerBase = Cast<APlayerBase>(GetPawn());
	ensure(PlayerBase != nullptr);
}

void ARunnerPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//InputComponent->BindAction("MoveLeft", IE_Pressed, )
}
