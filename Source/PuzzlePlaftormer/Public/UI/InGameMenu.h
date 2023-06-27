// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuInterface.h"
#include "MenuWidget.h"
#include "InGameMenu.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLAFTORMER_API UInGameMenu : public UMenuWidget
{
	GENERATED_BODY()
	
public:


UFUNCTION()
virtual void CloseMenu();

protected:
	UPROPERTY(meta = (BindWidget))
	class UButton* ReturnButton;
	
	UPROPERTY(meta = (BindWidget))
	class UButton* ExitButton;
	
	UPROPERTY(meta = (BindWidget))
	class UButton* CloseButton;

	virtual void NativeConstruct() override;

	virtual bool Initialize() override;

private:
UFUNCTION()
virtual void ReturnToMenu();


};
