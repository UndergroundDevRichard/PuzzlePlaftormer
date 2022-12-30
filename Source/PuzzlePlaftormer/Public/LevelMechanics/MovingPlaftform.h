// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlaftform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLAFTORMER_API AMovingPlaftform : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	// Sets Default Values for Static Mesh Actor
	AMovingPlaftform();
	
private:

	FVector GlobalStartLocation;
	FVector GlobalTargetLocation;
	UPROPERTY(EditAnywhere)
	int ActiveTriggers = 0;

	float MovementSpeed;

	bool bIsGoingToTarget;
	FVector CurrentTarget;
	virtual void CalculateDirection();

	bool bActivePlatform;

	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(Category = MovingPlatform, EditAnywhere, AdvancedDisplay)
		float TimeToReachTarget ;

	UPROPERTY(Category = MovingPlatform, EditAnywhere, Meta = (MakeEditWidget = true), AdvancedDisplay)
	FVector TargetLocation;

	FVector MovementDirection;
	
	virtual void BeginPlay() override;

	virtual void SetMovingPlatformMeshComponent();

	void AddActiveTrigger();
	void RemoveActiveTrigger();

};
