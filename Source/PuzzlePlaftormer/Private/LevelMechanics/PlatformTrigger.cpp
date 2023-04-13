// Fill out your copyright notice in the Description page of Project Settings.

#include "PlatformTrigger.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"

#include "MovingPlatform.h"


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
	TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &APlatformTrigger::OnOverlapBegin);
	TriggerVolume->OnComponentEndOverlap.AddDynamic(this, &APlatformTrigger::OnOverlapEnd);

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


//Changes properties in the construction script
void APlatformTrigger::PostEditChangeProperty(struct FPropertyChangedEvent& e)
{
	if (TriggerAsset != nullptr)
	{
		TriggerMesh->SetStaticMesh(TriggerAsset);
	}
	TriggerVolume->SetBoxExtent(BoxSize);
	Super::PostEditChangeProperty(e);
}

void APlatformTrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Role == ROLE_Authority)
	{
		UE_LOG(LogTemp, Warning, TEXT("Acti vated"));
		for (AMovingPlatform* Platform : PlatformsToTrigger)
		{
			{
				if (ensure(Platform != nullptr))
				{
					Platform->AddActiveTrigger();
				}
			}
		}
		
	}
}

void APlatformTrigger::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (Role == ROLE_Authority)
	{
		UE_LOG(LogTemp, Warning, TEXT("De Acti vated"));
		for (AMovingPlatform* Platform : PlatformsToTrigger)
		{
			{
				if (ensure(Platform != nullptr))
				{
					Platform->RemoveActiveTrigger();
				}
			}
		}

	}
}

