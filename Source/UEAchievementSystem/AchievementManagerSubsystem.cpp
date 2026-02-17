// Fill out your copyright notice in the Description page of Project Settings.


#include "AchievementManagerSubsystem.h"
#include "AchievementDefinition.h"
#include "AchievementProgress.h"

#include "AchievementSettings.h"
#include "Kismet/GameplayStatics.h"


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
		UAchievementProgress* Progress;
		
		if (UGameplayStatics::DoesSaveGameExist(Definition->ID.ToString(), 0))
		{
			Progress = Cast<UAchievementProgress>(UGameplayStatics::LoadGameFromSlot(Name.ToString(), 0));
		}
		else
		{
			Progress = NewObject<UAchievementProgress>();
			Progress->AchievementID = Name;
		}
		
		Progress->AchievementID = Name;
		AchievementProgresses.Add(Name, Progress);
	}
}

void UAchievementManagerSubsystem::UnlockAchievement(UAchievementProgress* Progress) const
{
	if (!Progress)
	{
		return;
	}
	
	Progress->IsCompleted = true;
	
	OnAchievementUnlocked.Broadcast(Progress->AchievementID);
	
	SaveAchievementProgress(Progress);
}

void UAchievementManagerSubsystem::SaveAchievementProgress(UAchievementProgress* Progress)
{
	UGameplayStatics::SaveGameToSlot(Progress, Progress->AchievementID.ToString(), 0);
}

UAchievementManagerSubsystem* UAchievementManagerSubsystem::GetInstance(const UObject* WorldContextObject)
{
	return WorldContextObject->GetWorld()->GetGameInstance()->GetSubsystem<UAchievementManagerSubsystem>();
}

const UAchievementDefinition* UAchievementManagerSubsystem::GetDefinition(const FName& AchievementID) const
{
	return *AchievementDefinitions.Find(AchievementID);
}

UAchievementProgress* UAchievementManagerSubsystem::GetProgress(const FName& AchievementID) const
{
	return *AchievementProgresses.Find(AchievementID);
}

TArray<FAchievementAndProgress> UAchievementManagerSubsystem::GetAchievementDefinitionsAndProgresses() const
{
	TArray<FAchievementAndProgress> Result;
	Result.Reserve(AchievementProgresses.Num());
	
	for (auto& [Name, Progress] : AchievementProgresses)
	{
		const UAchievementDefinition* Definition = GetDefinition(Name);
		Result.Add({Definition, Progress});
	}
	
	return Result;
}

void UAchievementManagerSubsystem::UnlockAchievement(const FName& AchievementID) const
{
	UAchievementProgress* Progress = GetProgress(AchievementID);
		
	UnlockAchievement(Progress);
}

void UAchievementManagerSubsystem::AddCounterProgress(const FName& AchievementID, const int ProgressValue)
{
	UAchievementProgress* Progress = GetProgress(AchievementID);
	const UAchievementDefinition* Definition = GetDefinition(AchievementID);
	
	if (!Progress)
	{
		return;
	}
	
	int newProgressValue = Progress->ProgressValue + ProgressValue;
	SetCounterProgress(Progress, newProgressValue);
}

void UAchievementManagerSubsystem::SetCounterProgress(const FName& AchievementID, const int ProgressValue)
{
	UAchievementProgress* Progress = GetProgress(AchievementID);
	
	if (!Progress)
	{
		return;
	}

	SetCounterProgress(Progress, ProgressValue);
}

void UAchievementManagerSubsystem::SetCounterProgress(UAchievementProgress* Progress, const int ProgressValue) const
{
	Progress->ProgressValue = ProgressValue;

	const UAchievementDefinition* Definition = GetDefinition(Progress->AchievementID);
	
	if (Progress->ProgressValue > Definition->TargetValue)
	{
		UnlockAchievement(Progress->AchievementID);
	}
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
