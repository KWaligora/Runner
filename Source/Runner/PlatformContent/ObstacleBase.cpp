#include "ObstacleBase.h"

#include "Components/BoxComponent.h"

// Sets default values
AObstacleBase::AObstacleBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
// Setup components
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	RootComponent = BoxComponent;
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Static Mesh");
	MeshComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AObstacleBase::BeginPlay()
{
	Super::BeginPlay();

// Get players actor for overlap test
	UWorld* World = GetWorld();
	if(!ensure(World != nullptr)) return;
	APlayerController* PlayerController = World->GetFirstPlayerController();
	if(!ensure(PlayerController != nullptr)) return;
	Player = PlayerController->GetPawn();
	if(!ensure(Player != nullptr)) return;
	
// Register OnComponentHit	
	BoxComponent->OnComponentHit.AddDynamic(this, &AObstacleBase::OnHit);
}

// Called every frame
void AObstacleBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AObstacleBase::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
	FVector NormalImpulse, const FHitResult& Hit)
{
	if(OtherActor == Player)
	{
		OnCollision();
	}
}
