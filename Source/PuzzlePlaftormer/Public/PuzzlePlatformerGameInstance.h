// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MainMenuInterface.h"
#include "PuzzlePlatformerGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLAFTORMER_API UPuzzlePlatformerGameInstance : public UGameInstance, public IMainMenuInterface
{
	GENERATED_BODY()
	
public:

	UPuzzlePlatformerGameInstance(const FObjectInitializer & ObjectInitializer);



public:
	UFUNCTION()
	virtual void Init();

	UFUNCTION(exec, BlueprintCallable)
	void LoadMenu();
	

	UFUNCTION(exec)
	void Host() override;

	UFUNCTION(exec)
	void Join(const FString& IPAddress) override;

	UFUNCTION(exec)
	void ReturnToMenu() override;


private:
	TSubclassOf<class UUserWidget> MenuClass;
	//UPROPERTY()
	//class UUserWidget* MenuWidget;

	class UMainMenu* Menu;

protected:


};
