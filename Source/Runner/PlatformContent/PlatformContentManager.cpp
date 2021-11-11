#include "PlatformContentManager.h"

#include "PlatformContent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UPlatformContentManager::UPlatformContentManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
}

// Called when the game starts
void UPlatformContentManager::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> OutActors;
	UGameplayStatics::GetAllActorsWithInterface(GetWorld(), UPlatformContent::StaticClass(), OutActors);
	
	int num = OutActors.Num();
	UE_LOG(LogTemp, Warning, TEXT("Contents: %d"), num);	
}


// Called every frame
void UPlatformContentManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

