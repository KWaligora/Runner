// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlatformContent.h"
#include "GameFramework/Pawn.h"
#include "EnemyBase.generated.h"

UCLASS()
class RUNNER_API AEnemyBase : public APawn, public IPlatformContent
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemyBase();

	// IPlatformContent implementation
	virtual FVector GetLocation()  override { return  GetActorLocation(); }
	virtual void SetLocation(FVector Location) override { SetActorLocation(Location); }
	virtual bool IsActiveBP() override {return IsActive(); } 
	virtual void OnEnableBP() override { OnEnable(); }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
// Components
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleComponent;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* SkeletalMeshComponent;
	
// Interface
	UFUNCTION(BlueprintImplementableEvent)
	bool IsActive();
	UFUNCTION(BlueprintImplementableEvent)
	void OnEnable();
};
