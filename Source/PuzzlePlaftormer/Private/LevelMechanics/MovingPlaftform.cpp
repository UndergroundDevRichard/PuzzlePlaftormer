// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlaftform.h"


AMovingPlaftform::AMovingPlaftform()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);

	DistanceTravelTick = 10;
	timeToCompleteACircuit = 5;

}

void AMovingPlaftform::BeginPlay()
{
	Super::BeginPlay();

	if (Role == ROLE_Authority)
	{
		SetReplicates(true);
		SetReplicateMovement(true);

		FVector StartLocation = GetActorLocation();
		MovementDirection = (TargetLocation + StartLocation) - StartLocation;
		MovementDirection.Normalize();
	}	
}

void AMovingPlaftform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (Role == ROLE_Authority)
	{
		FVector Location = GetActorLocation();
		Location += FVector(MovementDirection * (DistanceTravelTick * DeltaTime));
		SetActorLocation(Location);
	}
}


