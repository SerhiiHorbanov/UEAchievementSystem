// Fill out your copyright notice in the Description page of Project Settings.


#include "AchievementManagingFunctions.h"

#include "AchievementManagerSubsystem.h"

bool UAchievementManagingFunctions::IsAchievementUnlocked(const FName& AchievementID, const UObject* WorldContextObject)
{
	const UAchievementManagerSubsystem* AchievementManagerSubsystem = UAchievementManagerSubsystem::GetInstance(WorldContextObject);
	
	if (!AchievementManagerSubsystem)
	{
		return false;
	}	
	
	return AchievementManagerSubsystem->IsAchievementUnlocked(AchievementID);
}

void UAchievementManagingFunctions::UnlockAchievement(const FName& AchievementID, const UObject* WorldContextObject)
{
	const UAchievementManagerSubsystem* AchievementManagerSubsystem = UAchievementManagerSubsystem::GetInstance(WorldContextObject);
	if (AchievementManagerSubsystem)
	{
		AchievementManagerSubsystem->UnlockAchievement(AchievementID);
	}
}

void UAchievementManagingFunctions::AddProgressToAchievement(const FName& AchievementID, const int ProgressValue, const UObject* WorldContextObject)
{
	UAchievementManagerSubsystem* AchievementManagerSubsystem = UAchievementManagerSubsystem::GetInstance(WorldContextObject);
	if (AchievementManagerSubsystem)
	{
		AchievementManagerSubsystem->AddCounterProgress(AchievementID, ProgressValue);
	}
}

void UAchievementManagingFunctions::SetProgressOfAchievement(const FName& AchievementID, const int ProgressValue, const UObject* WorldContextObject)
{
	UAchievementManagerSubsystem* AchievementManagerSubsystem = UAchievementManagerSubsystem::GetInstance(WorldContextObject);
	if (AchievementManagerSubsystem)
	{
		AchievementManagerSubsystem->SetCounterProgress(AchievementID, ProgressValue);
	}
}
