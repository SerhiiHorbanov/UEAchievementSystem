// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AchievementAndProgress.h"
#include "AchievementManagerSubsystem.generated.h"

class UAchievementDefinition;
class UAchievementProgress;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAchievementUnlocked, const FName&, AchievementName);

UCLASS()
class UEACHIEVEMENTSYSTEM_API UAchievementManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
	UPROPERTY()
	TMap<FName, const UAchievementDefinition*> AchievementDefinitions;
	
	UPROPERTY()
	TMap<FName, UAchievementProgress*> AchievementProgresses;
	
public:
	
	UPROPERTY(EditAnywhere, BlueprintAssignable) 
	FAchievementUnlocked OnAchievementUnlocked;

	static UAchievementManagerSubsystem* GetInstance(const UObject* WorldContextObject);

	const UAchievementDefinition* GetDefinition(const FName& AchievementID) const;
	UAchievementProgress* GetProgress(const FName& AchievementID) const;
	
	TArray<FAchievementAndProgress> GetAchievementDefinitionsAndProgresses() const;
	
	void UnlockAchievement(const FName& AchievementID) const;
	void AddCounterProgress(const FName& AchievementID, const int ProgressValue);
	void SetCounterProgress(const FName& AchievementID, const int ProgressValue);
	
	bool IsAchievementUnlocked(const FName& AchievementID) const;
	
private:
	
	void LoadAchievementDefinitions();
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	void InitializeAchievementProgresses();

	void UnlockAchievement(UAchievementProgress* Progress) const;
	void SetCounterProgress(UAchievementProgress* Progress, const int ProgressValue) const;
	
	static void SaveAchievementProgress(UAchievementProgress* Progress);
};
