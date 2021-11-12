#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runner/PlatformContent/PlatformContent.h"
#include "PickupBase.generated.h"


UCLASS()
class RUNNER_API APickupBase : public AActor, public IPlatformContent
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
// IPlatformContent implementation
	virtual FVector GetLocation()  override { return  GetActorLocation(); }
	virtual void SetLocation(FVector Location) override { SetActorLocation(Location); }
	virtual bool IsActiveBP() override {return IsActive(); } 
	virtual void OnEnableBP() override { OnEnable(); }
	
protected:
// Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* StaticMesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class USphereComponent* SphereComponent;

	/*UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USound*/

	UPROPERTY()
	AActor* Player;
	
// Methods
	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent,	AActor* OtherActor,	UPrimitiveComponent* OtherComp,	int32 OtherBodyIndex, bool bFromSweep,	const FHitResult &SweepResult );

	UFUNCTION(BlueprintImplementableEvent)
	void OnPickup();

	UFUNCTION(BlueprintImplementableEvent)
	bool IsActive();
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnEnable();
};
