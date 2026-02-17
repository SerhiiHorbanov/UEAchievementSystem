// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "AchievementProgress.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAchievementProgressUpdated);

UCLASS()
class UEACHIEVEMENTSYSTEM_API UAchievementProgress : public USaveGame
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(BlueprintReadOnly, Category = "Progress")
	FName AchievementID;
	
	UPROPERTY(BlueprintReadOnly, Category = "Progress")
	bool IsCompleted;
	
	UPROPERTY(BlueprintReadOnly, Category = "Progress")
	int ProgressValue;
	
	UPROPERTY(BlueprintAssignable, Category = "Progress")
	FAchievementProgressUpdated OnProgressUpdated;
};
