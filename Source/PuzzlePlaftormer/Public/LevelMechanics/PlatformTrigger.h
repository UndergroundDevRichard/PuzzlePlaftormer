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
	
	UPROPERTY(EditDefaultsOnly, Category = "PlatformStats")
	UStaticMesh* TriggerAsset;

private:
	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	class UBoxComponent* TriggerVolume;
	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	class UStaticMeshComponent* TriggerMesh;
	UPROPERTY(EditDefaultsOnly, Category = "PlatformStats")
	FVector BoxSize;

	UPROPERTY(EditAnywhere)
	TArray<class AMovingPlaftform*> PlatformsToTrigger;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
