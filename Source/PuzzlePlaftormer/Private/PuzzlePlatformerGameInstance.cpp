// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzlePlatformerGameInstance.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"

UPuzzlePlatformerGameInstance::UPuzzlePlatformerGameInstance(const FObjectInitializer & ObjectInitializer)
{
	UE_LOG(LogTemp, Log, TEXT("Constructor"));
}

void UPuzzlePlatformerGameInstance::Init()
{
	Super::Init();
	UE_LOG(LogTemp, Log, TEXT("Init Function"));
}

void UPuzzlePlatformerGameInstance::Host()
{
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Hosting"));

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	World->ServerTravel("/Game/Maps/L_BaseLevel?listen");

}

void UPuzzlePlatformerGameInstance::Join(const FString& IPAddress)
{
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 5, FColor::Yellow, FString::Printf(TEXT("Joining : %s"), *IPAddress));

	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (!ensure(PC != nullptr)) return;
	PC->ClientTravel(IPAddress, TRAVEL_Absolute, true);

}
