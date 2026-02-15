// Fill out your copyright notice in the Description page of Project Settings.


#include "AchievementManagerSubsystem.h"
#include "AchievementDefinition.h"
#include "AchievementProgress.h"

#include "AchievementSettings.h"


void UAchievementManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	LoadAchievementDefinitions();
	InitializeAchievementProgresses();
}

void UAchievementManagerSubsystem::LoadAchievementDefinitions()
{
	const UAchievementSettings* Settings = GetDefault<UAchievementSettings>();
	const TArray<TSoftObjectPtr<UAchievementDefinition>>& Definitions = Settings->AchievementDefinitions;
	
	for (int i = 0; i < Definitions.Num(); i++)
	{
		const TSoftObjectPtr<UAchievementDefinition>& SoftObjectPtr = Definitions[i];
		const UAchievementDefinition* Definition = SoftObjectPtr.LoadSynchronous();
		
		if (!Definition)
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to load achievement definition %s. It is element %d"), *(SoftObjectPtr.ToString()), i);
			continue;
		}
		
		const FName& Name = Definition->ID;

		AchievementDefinitions.Add(Name, Definition);
	}
}

void UAchievementManagerSubsystem::InitializeAchievementProgresses()
{
	for (auto& [Name, Definition] : AchievementDefinitions)
	{
		UAchievementProgress* Progress = NewObject<UAchievementProgress>();
		Progress->AchievementID = Name;
		AchievementProgresses.Add(Name, Progress);
	}
}

UAchievementManagerSubsystem* UAchievementManagerSubsystem::GetInstance(const UObject* WorldContextObject)
{
	return WorldContextObject->GetWorld()->GetGameInstance()->GetSubsystem<UAchievementManagerSubsystem>();
}

void UAchievementManagerSubsystem::UnlockAchievement(const FName& AchievementID)
{
	UAchievementProgress* Progress = AchievementProgresses[AchievementID];
	
	Progress->IsCompleted = true;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Achievement unlocked"));
}

void UAchievementManagerSubsystem::AddProgress(const FName& AchievementID, const int ProgressValue)
{
	UAchievementProgress* Progress = *(AchievementProgresses.Find(AchievementID));
	
	if (!Progress)
	{
		return;
	}
	
	Progress->ProgressValue += ProgressValue;
}

void UAchievementManagerSubsystem::SetProgress(const FName& AchievementID, const int ProgressValue)
{
	UAchievementProgress* Progress = *(AchievementProgresses.Find(AchievementID));
	
	if (!Progress)
	{
		return;
	}

	Progress->ProgressValue = ProgressValue;
}

bool UAchievementManagerSubsystem::IsAchievementUnlocked(const FName& AchievementID) const
{
	const UAchievementProgress* Progress = *(AchievementProgresses.Find(AchievementID));
	
	if (!Progress)
	{
		return false;
	}
	
	return Progress->IsCompleted;
}
