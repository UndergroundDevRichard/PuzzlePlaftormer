// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformTrigger.generated.h"

UCLASS()
class PUZZLEPLAFTORMER_API APlatformTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatformTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& e) override;

private:
	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	class UBoxComponent* TriggerVolume;
	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	class UStaticMeshComponent* TriggerMesh;
	UPROPERTY(EditDefaultsOnly, Category = "PlatformStats")
	FVector BoxSize;

};
