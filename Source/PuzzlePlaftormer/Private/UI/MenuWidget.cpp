// Fill out your copyright notice in the Description page of Project Settings.

#include "MenuWidget.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Kismet/KismetSystemLibrary.h"


void UMenuWidget::SetupMenu()
{
	this->AddToViewport();

	PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (!ensure(PC != nullptr)) return;

	FInputModeUIOnly InputData;
	InputData.SetWidgetToFocus(this->TakeWidget());
	InputData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);


	PC->SetInputMode(InputData);
	PC->bShowMouseCursor = true;


}

void UMenuWidget::TeardownMenu()
{
	if (!ensure(PC != nullptr)) return;

	FInputModeGameOnly InputData;

	PC->SetInputMode(InputData);
	PC->bShowMouseCursor = false;
	this->RemoveFromViewport();
	//UWidgetLayoutLibrary::RemoveAllWidgets(this);
}

void UMenuWidget::SetMenuInterface(IMainMenuInterface* MenuInterface)
{
	this->MenuInterface = MenuInterface;
}

void UMenuWidget::Quit()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), 0, EQuitPreference::Quit);
}


