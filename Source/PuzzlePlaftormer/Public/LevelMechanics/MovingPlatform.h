// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class PUZZLEPLAFTORMER_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	class UStaticMeshComponent* Mesh;
	class USceneComponent* Base;

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

	UPROPERTY(Category = MovingPlatform, EditAnywhere, AdvancedDisplay)
		float MaxSmoothNetUpdateDistance;
	float SmoothLocationTime;
	FVector MeshTranslationOffset;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(Category = MovingPlatform, EditAnywhere, AdvancedDisplay)
		float TimeToReachTarget;

	UPROPERTY(Category = MovingPlatform, EditAnywhere, Meta = (MakeEditWidget = true), AdvancedDisplay)
	FVector TargetLocation;

	FVector MovementDirection;

	void AddActiveTrigger();
	void RemoveActiveTrigger();
};
