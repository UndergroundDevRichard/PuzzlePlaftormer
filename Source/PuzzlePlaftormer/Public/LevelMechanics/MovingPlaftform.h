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

	UPROPERTY(Category = MovingPlatform, EditAnywhere, AdvancedDisplay)
	float DistanceTravelTick;

	UPROPERTY(Category = MovingPlatform, EditAnywhere, Meta=(MakeEditWidget = true), AdvancedDisplay)
	FVector TargetLocation;

	FVector MovementDirection;

	float timeToCompleteACircuit;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void BeginPlay() override;
};
