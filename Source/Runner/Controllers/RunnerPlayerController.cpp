#include "RunnerPlayerController.h"
#include "Runner/Characters/PlayerBase.h"

void ARunnerPlayerController::BeginPlay()
{
	Super::BeginPlay();

	PlayerBase = Cast<APlayerBase>(GetPawn());
	ensure(PlayerBase != nullptr);
	
	CalculatePaths();
}

void ARunnerPlayerController::CalculatePaths()
{
	float PathSize = TrackSize / PathCount;
	for(int i = 0; i < PathCount; i++)
	{
		Paths.Add(FVector(0, PathSize / 2 + i * PathSize, 110));
	}
}

void ARunnerPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//InputComponent->BindAction("MoveLeft", IE_Pressed, )
}
