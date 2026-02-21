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
	TMap<FName, UAchievementDefinition*> AchievementDefinitions;
	
	UPROPERTY()
	TMap<FName, UAchievementProgress*> AchievementProgresses;
	
public:
	
	UPROPERTY(EditAnywhere, BlueprintAssignable) 
	FAchievementUnlocked OnAchievementUnlocked;

	UFUNCTION(BlueprintPure, Category = "Achievements", meta = (WorldContext = "WorldContextObject"))
	static UAchievementManagerSubsystem* GetInstance(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category = "Achievements")
	UAchievementDefinition* GetDefinition(const FName& AchievementID) const;

	UFUNCTION(BlueprintCallable, Category = "Achievements")
	UAchievementProgress* GetProgress(const FName& AchievementID) const;
	
	UFUNCTION(BlueprintCallable, Category = "Achievements")
	TArray<FAchievementAndProgress> GetAchievementDefinitionsAndProgresses() const;
	
	UFUNCTION(BlueprintCallable, Category = "Achievements")
	void UnlockAchievement(const FName& AchievementID);

	UFUNCTION(BlueprintCallable, Category = "Achievements")
	void AddCounterProgress(const FName& AchievementID, const int ProgressValue);

	UFUNCTION(BlueprintCallable, Category = "Achievements")
	void SetCounterProgress(const FName& AchievementID, const int ProgressValue);
	
	UFUNCTION(BlueprintPure, Category = "Achievements")
	bool IsAchievementUnlocked(const FName& AchievementID) const;
	
private:
	
	void LoadAchievementDefinitions();
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	void InitializeAchievementProgresses();

	void UnlockAchievement(UAchievementProgress* Progress);
	void SetCounterProgress(UAchievementProgress* Progress, const int ProgressValue);
	
	static void SaveAchievementProgress(UAchievementProgress* Progress);
};
