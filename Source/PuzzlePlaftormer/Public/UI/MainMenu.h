// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLAFTORMER_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()

public:

	
protected:

	UPROPERTY(meta = (BindWidget))
	class UButton* HostButton;
	
	UPROPERTY(meta = (BindWidget))
	class UButton* JoinMenuButton;
	
	UPROPERTY(meta = (BindWidget))
	class UButton* JoinButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* JoinMenuBackButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* QuitButton;

	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitcher;

	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* IPTextfield;

	UPROPERTY(meta = (BindWidget))
	class UWidget* MenuA;

	UPROPERTY(meta = (BindWidget))
	class UWidget* MenuB;


	virtual void NativeConstruct() override;
	virtual bool Initialize() override;

	UFUNCTION()
	virtual void HostServer();
	UFUNCTION()
	virtual void OpenJoinMenu();
	UFUNCTION()
	virtual void CloseJoinMenu();
	UFUNCTION()
	virtual void JoinServer();


private:

};
