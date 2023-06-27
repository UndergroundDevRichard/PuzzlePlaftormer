// Fill out your copyright notice in the Description page of Project Settings.

#include "InGameMenu.h"
#include "Components/Button.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "MenuWidget.h"


void UInGameMenu::NativeConstruct()
{
	Super::NativeConstruct();
}

bool UInGameMenu::Initialize()
{
	bool Success = Super::Initialize();

	if (!Success) return false;

	if (!ensure(ReturnButton != nullptr)) return false;
	ReturnButton->OnClicked.AddDynamic(this, &UInGameMenu::ReturnToMenu);
	if (!ensure(ExitButton != nullptr)) return false;
	ExitButton->OnClicked.AddDynamic(this, &UInGameMenu::Quit);
	if (!ensure(CloseButton != nullptr)) return false;
	CloseButton->OnClicked.AddDynamic(this, &UInGameMenu::CloseMenu);
	return true;
}

void UInGameMenu::ReturnToMenu()
{
	if (MenuInterface != nullptr)
	{
		TeardownMenu();
		MenuInterface->ReturnToMenu();
	}
	UE_LOG(LogTemp, Log, TEXT("I am Leaving a game!"));
}

void UInGameMenu::CloseMenu()
{
	TeardownMenu();
}
