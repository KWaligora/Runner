#include "PlatformBase.h"


// Sets default values
APlatformBase::APlatformBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	StaticMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APlatformBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlatformBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	HandleMove(DeltaTime);	
}

// Allow move or stop move and set movement speed
void APlatformBase::SetMovement(float Speed, bool Value)
{
	MovementSpeed = Speed;
	CanMove = Value;	
}

void APlatformBase::HandleMove(float DeltaTime)
{
	if(CanMove)
	{
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation.X -= MovementSpeed * DeltaTime;
		SetActorLocation(CurrentLocation);
	}
}

