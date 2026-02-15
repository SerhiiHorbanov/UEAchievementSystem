// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "AchievementSettings.generated.h"

class UAchievementDefinition;

UCLASS(Config=Editor, DefaultConfig, meta=(DisplayName="My Editor Settings"))
class UEACHIEVEMENTSYSTEM_API UAchievementSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(Config, EditAnywhere, Category = "Achievements")
	TArray<TSoftObjectPtr<UAchievementDefinition>> AchievementDefinitions;
	
};
