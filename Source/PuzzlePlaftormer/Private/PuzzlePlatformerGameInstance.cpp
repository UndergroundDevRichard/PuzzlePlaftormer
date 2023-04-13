// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzlePlatformerGameInstance.h"
#include "Engine/Engine.h"


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
}

void UPuzzlePlatformerGameInstance::Join(const FString& IPAddress)
{
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 5, FColor::Yellow, FString::Printf(TEXT("Joining : %s"), *IPAddress));
}