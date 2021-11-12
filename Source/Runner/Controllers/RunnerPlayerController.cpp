#include "RunnerPlayerController.h"

#include "Kismet/GameplayStatics.h"
#include "Runner/RunnerGameModeBase.h"
#include "Runner/Characters/PlayerCharacter.h"

void ARunnerPlayerController::CheckPlayersHeight()
{
	if(PlayerChar->GetActorLocation().Z < 0)
		PlayerChar->OnDeath();
}

void ARunnerPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	HandleMovement(DeltaSeconds);
	
	CheckPlayersHeight();
}

void ARunnerPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
// Get refs
	PlayerChar = Cast<APlayerCharacter>(GetCharacter());
	if(!ensure(PlayerChar != nullptr)) return;
	
	ARunnerGameModeBase* GameMode = Cast<ARunnerGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if(!ensure(GameMode != nullptr)) return;
	
// Setup paths data
	GameMode->GetPaths(Paths);
	PathSize = GameMode->GetPathSize();
	
	MovePlayerToMiddlePath();

	int num = Paths.Num();
	UE_LOG(LogTemp, Warning, TEXT("Paths: %d"), num);
}

void ARunnerPlayerController::MovePlayerToMiddlePath()
{
	if(Paths.Num() <= 0) return;
	
	CurrentPath = FMath::DivideAndRoundDown(Paths.Num(), 2);	
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
	CurrentLocation.X = 0;
	PlayerChar->SetActorLocation(CurrentLocation);
}

void ARunnerPlayerController::Jump()
{
	PlayerChar->Jump();
}

