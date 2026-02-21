// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "AchievementSettings.generated.h"

class UAchievementDefinition;

UCLASS(Config=Game, DefaultConfig, meta=(DisplayName="Achievements"))
class UEACHIEVEMENTSYSTEM_API UAchievementSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:

	UPROPERTY(Config, EditAnywhere, Category = "Settings")
	TArray<TSoftObjectPtr<UAchievementDefinition>> AchievementDefinitions;

	UPROPERTY(Config, EditAnywhere, Category = "Settings")
	bool EnableLogs;

	UPROPERTY(Config, EditAnywhere, Category = "Settings")
	bool AllowHiddenAchievements;
};
