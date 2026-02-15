// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AchievementManagerSubsystem.generated.h"

class UAchievementDefinition;
class UAchievementProgress;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAchievementUnlocked, const FName&, AchievementName);

UCLASS()
class UEACHIEVEMENTSYSTEM_API UAchievementManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	
	UPROPERTY()
	TMap<FName, const UAchievementDefinition*> AchievementDefinitions;
	
	UPROPERTY()
	TMap<FName, UAchievementProgress*> AchievementProgresses;
	
	UPROPERTY()
	FAchievementUnlocked OnAchievementUnlocked;

	void LoadAchievementDefinitions();
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	void InitializeAchievementProgresses();

	void UnlockAchievement(const FName& AchievementID);
	void AddProgress(const FName& AchievementID, const int ProgressValue);
	void SetProgress(const FName& AchievementID, const int ProgressValue);
	
	bool IsAchievementUnlocked(const FName& AchievementID) const;
	
private:
	
	
};
