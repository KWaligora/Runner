#include "RunnerPlayerController.h"
#include "Runner/Characters/PlayerCharacter.h"

void ARunnerPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	HandleMovement(DeltaSeconds);
}

void ARunnerPlayerController::BeginPlay()
{
	Super::BeginPlay();

	PlayerChar = Cast<APlayerCharacter>(GetCharacter());
	ensure(PlayerChar != nullptr);
	
	CalculatePaths();
	MovePlayerToMiddlePath();
}
// Calculate path's size and location
void ARunnerPlayerController::CalculatePaths()
{
	PathSize = TrackSize / PathCount;
	for(int i = 0; i < PathCount; i++)
	{
		Paths.Add(FVector(0, PathSize / 2 + i * PathSize, 130));
	}
}

void ARunnerPlayerController::MovePlayerToMiddlePath()
{
	if(Paths.Num() <= 0) return;
	
	CurrentPath = FMath::DivideAndRoundDown(PathCount, 2);	
	PlayerChar->SetActorLocation(Paths[CurrentPath]);
}

void ARunnerPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("MoveLeft", IE_Pressed, this, &ARunnerPlayerController::MoveLeft);
	InputComponent->BindAction("MoveRight", IE_Pressed, this, &ARunnerPlayerController::MoveRight);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ARunnerPlayerController::Jump);
}

void ARunnerPlayerController::MoveLeft()
{
	if(CurrentPath <= 0) return;
	CurrentPath--;
}

void ARunnerPlayerController::MoveRight()
{
	if(CurrentPath >= Paths.Num() - 1) return;
	CurrentPath++;
}
// Interpolate to CurrentPath
void ARunnerPlayerController::HandleMovement(float DeltaSeconds)
{
	FVector CurrentLocation = PlayerChar->GetActorLocation();
	CurrentLocation.Y = FMath::FInterpConstantTo(CurrentLocation.Y, Paths[CurrentPath].Y, DeltaSeconds, PathSize * PathChangeSpeed);
	PlayerChar->SetActorLocation(CurrentLocation);
}

void ARunnerPlayerController::Jump()
{
	PlayerChar->Jump();
}

