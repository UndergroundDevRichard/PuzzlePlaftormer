// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"


// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Base = CreateDefaultSubobject<USceneComponent>(FName("BaseComp"));
	RootComponent = Base;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));

	Mesh->SetMobility(EComponentMobility::Movable);
 	Mesh->SetupAttachment(RootComponent);

	TimeToReachTarget = 3;
	MaxSmoothNetUpdateDistance = 5;
	SmoothLocationTime = 0.125;


}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
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
		bIsGoingToTarget = false;
		CalculateDirection();

	}
	
}

void AMovingPlatform::AddActiveTrigger()
{
	if (Role == ROLE_Authority)
	{
		ActiveTriggers++;
	}
}

void AMovingPlatform::RemoveActiveTrigger()
{
	if (Role == ROLE_Authority)
	{
		if (ActiveTriggers > 0)
		{
			ActiveTriggers--;
		}
	}
}


void AMovingPlatform::CalculateDirection()
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

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (ActiveTriggers > 0)
	{
		if (Role == ROLE_Authority)
		{

			FVector Location = GetActorLocation();
			FVector OldLocation = Location;
			Location += MovementSpeed * DeltaTime * MovementDirection;
			SetActorLocation(Location);
			FVector NewLocation = Location;
			// Mesh doesn't move, collision root does so we have a new offset.
			FVector NewToOldVector = (OldLocation - NewLocation);
			float InterpDistance = NewToOldVector.Size();
			if (InterpDistance > MaxSmoothNetUpdateDistance)
			{
				MeshTranslationOffset = FVector::ZeroVector;
			}
			else
			{
				MeshTranslationOffset = MeshTranslationOffset + NewToOldVector;
			}

			if (DeltaTime < SmoothLocationTime) //Smooth Location Time is about 0.125 Seconds
			{
				MeshTranslationOffset = MeshTranslationOffset * (1.f - DeltaTime / SmoothLocationTime);
			}
			else
			{
				MeshTranslationOffset = FVector::ZeroVector;
			}
			FVector NewRelTranslation = MeshTranslationOffset + FVector::ZeroVector;
			Mesh->SetRelativeLocation(NewRelTranslation);
			
			//Check if it's time to go back the way it came.
			FVector Delta = Location - CurrentTarget;
			float DistanceToGoal = Delta.Size();

			if (DistanceToGoal < 5)
			{
				CalculateDirection();
			}
		}
	}

}

