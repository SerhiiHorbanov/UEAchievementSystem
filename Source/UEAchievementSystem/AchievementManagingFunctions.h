// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AchievementManagerSubsystem.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AchievementManagingFunctions.generated.h"

UCLASS()
class UEACHIEVEMENTSYSTEM_API UAchievementManagingFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category = "Achievements", meta = (WorldContext = "WorldContextObject"))
	static bool IsAchievementUnlocked(const FName& AchievementID, const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category = "Achievements", meta = (WorldContext = "WorldContextObject"))
	static void UnlockAchievement(const FName& AchievementID, const UObject* WorldContextObject);
	
	UFUNCTION(BlueprintCallable, Category = "Achievements", meta = (WorldContext = "WorldContextObject"))
	static void AddProgressToAchievement(const FName& AchievementID, const int ProgressValue, const UObject* WorldContextObject);
	
	UFUNCTION(BlueprintCallable, Category = "Achievements", meta = (WorldContext = "WorldContextObject"))
	static void SetProgressOfAchievement(const FName& AchievementID, const int ProgressValue, const UObject* WorldContextObject);
};
