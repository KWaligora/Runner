#include "ContentSpawner.h"

#include "Kismet/GameplayStatics.h"
#include "Runner/RunnerGameModeBase.h"

// Sets default values for this component's properties
UContentSpawner::UContentSpawner()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UContentSpawner::BeginPlay()
{
	Super::BeginPlay();
// Get ContentManager from GameMode
	ARunnerGameModeBase* GameMode =  Cast<ARunnerGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if(!ensure(GameMode != nullptr)) return;
	UPlatformContentManager* ContentManager = GameMode->GetContentManager();
	if(!ensure(ContentManager != nullptr)) return;
}


// Called every frame
void UContentSpawner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UContentSpawner::SetupContent()
{
	
}

