#pragma once

#include "CoreMinimal.h"
#include "PlatformContent.h"
#include "GameFramework/Actor.h"
#include "ObstacleBase.generated.h"

UCLASS()
class RUNNER_API AObstacleBase : public AActor, public IPlatformContent
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObstacleBase();

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
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* MeshComponent;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* BoxComponent;
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnCollision();
	UFUNCTION(BlueprintImplementableEvent)
	bool IsActive();
	UFUNCTION(BlueprintImplementableEvent)
	void OnEnable();

private:
	UPROPERTY()
	AActor* Player;
	
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
};
