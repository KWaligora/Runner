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
	
	FindAllPlatformContent();
}


// Called every frame
void UPlatformContentManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	CheckOccupied();
}

void UPlatformContentManager::FindAllPlatformContent()
{
	TArray<AActor*> OutActors;
	UGameplayStatics::GetAllActorsWithInterface(GetWorld(), UPlatformContent::StaticClass(), OutActors);

	for(AActor* Actor : OutActors)
	{
		IPlatformContent* PlatformContent = Cast<IPlatformContent>(Actor);
		if(PlatformContent != nullptr)
		{
			OccupiedContent.Add(PlatformContent);
		}
	}
}

void UPlatformContentManager::CheckOccupied()
{
	for(int i = 0; i < OccupiedContent.Num(); i++)
	{
		if(OccupiedContent[i]->GetLocation().X < -1000)
		{
			FreeContent.Add(OccupiedContent[i]);
			OccupiedContent.RemoveAt(i);
		}
	}
}

IPlatformContent* UPlatformContentManager::GetContent()
{	
	if(FreeContent.Num() < 1) return nullptr;
	
	int RandomNum = FMath::RandRange(0, FreeContent.Num() - 1);
	IPlatformContent* Content =  FreeContent[RandomNum];
	
	FreeContent.RemoveAt(RandomNum);
	OccupiedContent.Add(Content);

	return Content;
}

