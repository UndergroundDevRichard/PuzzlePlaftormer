// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzlePlatformerGameInstance.h"
#include "PlatformTrigger.h"

#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"

UPuzzlePlatformerGameInstance::UPuzzlePlatformerGameInstance(const FObjectInitializer & ObjectInitializer)
{
	UE_LOG(LogTemp, Log, TEXT("Constructor"));

	//	/ Game / UI / Menus / WBP_MainMenu.WBP_MainMenu
	ConstructorHelpers::FClassFinder<UUserWidget> MenuBPClass(TEXT("/Game/UI/Menus/WBP_MainMenu"));
	if (!ensure(MenuBPClass.Class != nullptr)) return;

	MenuClass = MenuBPClass.Class;
}

void UPuzzlePlatformerGameInstance::Init()
{
	Super::Init();
	UE_LOG(LogTemp, Log, TEXT("Init Function"));

	UE_LOG(LogTemp, Log, TEXT("Found class %s"), *MenuClass->GetName());
}

void UPuzzlePlatformerGameInstance::Host()
{
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Hosting"));

	UWorld* World = GetWorld();
	if (!ensure(World != NULL)) return;

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
