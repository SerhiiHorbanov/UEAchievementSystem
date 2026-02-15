// Fill out your copyright notice in the Description page of Project Settings.


#include "AchievementManagingFunctions.h"

#include "AchievementManagerSubsystem.h"

bool UAchievementManagingFunctions::IsAchievementUnlocked(const FName& AchievementID, const UObject* WorldContextObject)
{
	const UAchievementManagerSubsystem* AchievementManagerSubsystem = GetAchievementManagerSubsystem(WorldContextObject);
	
	if (!AchievementManagerSubsystem)
	{
		return false;
	}	
	
	return AchievementManagerSubsystem->IsAchievementUnlocked(AchievementID);
}

UAchievementManagerSubsystem* UAchievementManagingFunctions::GetAchievementManagerSubsystem(const UObject* WorldContextObject)
{
	return WorldContextObject->GetWorld()->GetGameInstance()->GetSubsystem<UAchievementManagerSubsystem>();
}

void UAchievementManagingFunctions::UnlockAchievement(const FName& AchievementID, const UObject* WorldContextObject)
{
	UAchievementManagerSubsystem* AchievementManagerSubsystem = GetAchievementManagerSubsystem(WorldContextObject);
	if (AchievementManagerSubsystem)
	{
		AchievementManagerSubsystem->UnlockAchievement(AchievementID);
	}
}

void UAchievementManagingFunctions::AddProgressToAchievement(const FName& AchievementID, const int ProgressValue, const UObject* WorldContextObject)
{
	UAchievementManagerSubsystem* AchievementManagerSubsystem = GetAchievementManagerSubsystem(WorldContextObject);
	if (AchievementManagerSubsystem)
	{
		AchievementManagerSubsystem->AddProgress(AchievementID, ProgressValue);
	}
}

void UAchievementManagingFunctions::SetProgressOfAchievement(const FName& AchievementID, const int ProgressValue, const UObject* WorldContextObject)
{
	UAchievementManagerSubsystem* AchievementManagerSubsystem = GetAchievementManagerSubsystem(WorldContextObject);
	if (AchievementManagerSubsystem)
	{
		AchievementManagerSubsystem->SetProgress(AchievementID, ProgressValue);
	}
}
