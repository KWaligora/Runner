#include "RunnerPlayerController.h"
#include "Runner/Characters/PlayerBase.h"

void ARunnerPlayerController::BeginPlay()
{
	Super::BeginPlay();

	PlayerBase = Cast<APlayerBase>(GetPawn());
	ensure(PlayerBase != nullptr);
	
	CalculatePaths();
	MovePlayerToMiddlePath();
}

void ARunnerPlayerController::CalculatePaths()
{
	float PathSize = TrackSize / PathCount;
	for(int i = 0; i < PathCount; i++)
	{
		Paths.Add(FVector(0, PathSize / 2 + i * PathSize, 110));
	}
}

void ARunnerPlayerController::MovePlayerToMiddlePath()
{
	if(Paths.Num() <= 0) return;
	
	CurrentPath = FMath::DivideAndRoundDown(PathCount, 2);	
	PlayerBase->SetActorLocation(Paths[CurrentPath]);
}

void ARunnerPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("MoveLeft", IE_Pressed, this, &ARunnerPlayerController::MoveLeft);
	InputComponent->BindAction("MoveRight", IE_Pressed, this, &ARunnerPlayerController::MoveRight);
}

void ARunnerPlayerController::MoveLeft()
{
	if(CurrentPath <= 0) return;

	CurrentPath--;
	PlayerBase->SetActorLocation(Paths[CurrentPath]);
}

void ARunnerPlayerController::MoveRight()
{
	if(CurrentPath >= Paths.Num() - 1) return;

	CurrentPath++;
	PlayerBase->SetActorLocation(Paths[CurrentPath]);
}
