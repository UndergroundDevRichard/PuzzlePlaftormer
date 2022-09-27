// Fill out your copyright notice in the Description page of Project Settings.

#include "PlatformTrigger.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"


// Sets default values
APlatformTrigger::APlatformTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(FName("TriggerVolume"));
	BoxSize = FVector(150.0f, 150.0f, 150.0f);
	TriggerVolume->SetBoxExtent(BoxSize);
	if (!ensure(TriggerVolume != nullptr)) return;
	RootComponent = TriggerVolume;

	TriggerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TriggerMesh"));
	TriggerMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	TriggerMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APlatformTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlatformTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void APlatformTrigger::PostEditChangeProperty(struct FPropertyChangedEvent& e)
{
	TriggerVolume->SetBoxExtent(BoxSize);
	Super::PostEditChangeProperty(e);
}

