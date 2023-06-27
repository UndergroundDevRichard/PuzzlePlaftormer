// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableTextBox.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "MenuWidget.h"


void UMainMenu::NativeConstruct()
{
	Super::NativeConstruct();
}

bool UMainMenu::Initialize()
{
	bool Success = Super::Initialize();
	
	if (!Success) return false;

	if (!ensure(HostButton != nullptr)) return false;
	HostButton->OnClicked.AddDynamic(this,&UMainMenu::HostServer);
	if (!ensure(JoinMenuButton != nullptr)) return false;
	JoinMenuButton->OnClicked.AddDynamic(this, &UMainMenu::OpenJoinMenu);
	if (!ensure(JoinButton != nullptr)) return false;
	JoinButton->OnClicked.AddDynamic(this, &UMainMenu::JoinServer);
	if (!ensure(JoinMenuBackButton != nullptr)) return false;
	JoinMenuBackButton->OnClicked.AddDynamic(this, &UMainMenu::CloseJoinMenu);
	if (!ensure(QuitButton != nullptr)) return false;
	QuitButton->OnClicked.AddDynamic(this, &UMainMenu::Quit);
	
	return true;
}

//Menu Management
void UMainMenu::OpenJoinMenu()
{
	UE_LOG(LogTemp, Log, TEXT("Join Menu Clicked"));
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(MenuB != nullptr)) return;
	MenuSwitcher->SetActiveWidget(MenuB);
}

void UMainMenu::CloseJoinMenu()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(MenuA != nullptr)) return;
	MenuSwitcher->SetActiveWidget(MenuA);
}

//Deal with MultiplayerServers

void UMainMenu::HostServer()
{
	if (MenuInterface != nullptr)
	{
		MenuInterface->Host();
	}
	UE_LOG(LogTemp, Log, TEXT("I am Hosting a game!"));
}

void UMainMenu::JoinServer()
{
	FString IpAddress = IPTextfield->GetText().ToString();
	if (MenuInterface != nullptr)
	{
		MenuInterface->Join(IpAddress);
	}
	UE_LOG(LogTemp, Log, TEXT("I am Joining a game!"));
}


