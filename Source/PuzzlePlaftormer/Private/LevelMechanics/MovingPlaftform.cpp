// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlaftform.h"
#include "Kismet/KismetMathLibrary.h"


AMovingPlaftform::AMovingPlaftform()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);

	TimeToReachTarget = 3;

}

void AMovingPlaftform::BeginPlay()
{
	Super::BeginPlay();



	if (Role == ROLE_Authority)
	{
		SetReplicates(true);
		SetReplicateMovement(true);

		MovementSpeed = TargetLocation.Size() / TimeToReachTarget;
		abs(MovementSpeed);
		GlobalStartLocation = GetActorLocation();
		GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
		bIsGoingToTarget = true;
		CalculateDirection();

	}	
}

void AMovingPlaftform::SetMovingPlatformMeshComponent()
{
	

}

void AMovingPlaftform::CalculateDirection()
{
	if (bIsGoingToTarget) 
	{
		MovementDirection = (GlobalStartLocation - GlobalTargetLocation).GetSafeNormal();
		bIsGoingToTarget = false;
		CurrentTarget = GlobalStartLocation;
	}
	else
	{
		MovementDirection = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
		bIsGoingToTarget = true;
		CurrentTarget = GlobalTargetLocation;
	}

}

void AMovingPlaftform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (Role == ROLE_Authority)
	{
		FVector Location = GetActorLocation();
		Location += MovementSpeed * DeltaTime * MovementDirection;
		SetActorLocation(Location);

		FVector Delta = Location - CurrentTarget;
		float DistanceToGoal = Delta.Size();

		if (DistanceToGoal < 5)
		{
			CalculateDirection();
		}
		
	}
}


