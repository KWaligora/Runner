#include "PlatformManager.h"

#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Runner/Platforms/PlatformBase.h"

// Sets default values
APlatformManager::APlatformManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	BoxComponent->SetCollisionProfileName(TEXT("Trigger"));
}

void APlatformManager::SetSpeed(float Speed)
{
	PlatformSpeed = Speed;

	for(APlatformBase* Platform : OccupiedPlatforms)
	{
		Platform->SetMovement(Speed);
	}
}

// Called when the game starts or when spawned
void APlatformManager::BeginPlay()
{
	Super::BeginPlay();

	BoxComponent->OnComponentEndOverlap.AddDynamic(this, &APlatformManager::OnOverlapEnd);

	FindPlatforms();
}

// Called every frame
void APlatformManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CheckOccupied();
}

// Get all platforms from scene to array
void APlatformManager::FindPlatforms()
{
	TArray<AActor*> OutActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), PlatformClass, OutActors);
	
	for(AActor* Actor : OutActors)
	{
		APlatformBase* Platform = Cast<APlatformBase>(Actor);
		if(Platform != nullptr)
		{
			OccupiedPlatforms.Add(Platform);
			Platform->SetMovement(PlatformSpeed, true);
		}
	}
}

void APlatformManager::CheckOccupied()
{
	for(int i = 0; i < OccupiedPlatforms.Num(); i++)
		{
		if(OccupiedPlatforms[i]->GetActorLocation().X < -2000)
		{
			OccupiedPlatforms[i]->SetMovement(0, false);
			FreePlatforms.Add(OccupiedPlatforms[i]);
			OccupiedPlatforms.RemoveAt(i);
		}
	}
}

void APlatformManager::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if(OtherActor != nullptr && OtherActor != this)
	{
		SpawnPlatform();
	}	
}

void APlatformManager::SpawnPlatform()
{
	if(FreePlatforms.Num() < 1) return;
	int RandomNumber = FMath::RandRange(0, FreePlatforms.Num() - 1);

	APlatformBase* Platform = FreePlatforms[RandomNumber];
	FreePlatforms.RemoveAt(RandomNumber);
	
	FVector NewLocation = FVector(0,400,0);
	NewLocation.X = GetActorLocation().X + PlatformsGap + Platform->GetOriginOffset();
	Platform->SetActorLocation(NewLocation);
	Platform->SetMovement(PlatformSpeed, true);
	Platform->OnSpawn().Broadcast();

	OccupiedPlatforms.Add(Platform);
}

