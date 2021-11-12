#include "ContentSpawner.h"

#include "PlatformContent.h"
#include "PlatformContentManager.h"
#include "Kismet/GameplayStatics.h"
#include "Runner/RunnerGameModeBase.h"
#include "Runner/Platforms/PlatformBase.h"

// Sets default values for this component's properties
UContentSpawner::UContentSpawner()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UContentSpawner::BeginPlay()
{
	Super::BeginPlay();
// Get ContentManager from GameMode
	ARunnerGameModeBase* GameMode =  Cast<ARunnerGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if(!ensure(GameMode != nullptr)) return;
	ContentManager = GameMode->GetContentManager();
	if(!ensure(ContentManager != nullptr)) return;
	
	APlatformBase* PlatformBase = Cast<APlatformBase>(GetOwner());
	if(!ensure(PlatformBase != nullptr)) return;

// Subscribe OnSpawn Event
	PlatformBase->OnSpawn().AddUObject(this, &UContentSpawner::SetupContent);
}


// Called every frame
void UContentSpawner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(CurrentContent != nullptr && CurrentContent->IsActiveBP())
		CurrentContent->SetLocation(GetComponentLocation());
}

void UContentSpawner::SetupContent()
{
	CurrentContent = ContentManager->GetContent();
	CurrentContent->OnEnableBP();
}

