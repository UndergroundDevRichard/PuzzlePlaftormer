// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuInterface.h"
#include "MenuWidget.generated.h"



/**
 * 
 */
UCLASS()
class PUZZLEPLAFTORMER_API UMenuWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	void SetupMenu();

	void TeardownMenu();

	void SetMenuInterface(IMainMenuInterface* MenuInterface);
protected:
	IMainMenuInterface* MenuInterface;

	class APlayerController* PC;

	UFUNCTION()
	virtual void Quit();

private:

	
};
