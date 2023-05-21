// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PuzzlePlatformerGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLAFTORMER_API UPuzzlePlatformerGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

	UPuzzlePlatformerGameInstance(const FObjectInitializer & ObjectInitializer);



public:
	UFUNCTION()
	virtual void Init();

	UFUNCTION(exec)
	void Host();

	UFUNCTION(exec)
	void Join(const FString& IPAddress);

private:
	TSubclassOf<class UUserWidget> MenuClass;
	//UPROPERTY()
	//class UUserWidget* MenuWidget;
	

};
