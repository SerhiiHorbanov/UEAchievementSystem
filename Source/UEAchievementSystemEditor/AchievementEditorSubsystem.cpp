#include "AchievementEditorSubsystem.h"
#include "../UEAchievementSystem/AchievementManagerSubsystem.h"
#include "../UEAchievementSystem/AchievementProgress.h"

void UAchievementEditorSubsystem::ForceUnlockAchievement(FName AchievementID)
{
	UAchievementManagerSubsystem* Subsystem = UAchievementManagerSubsystem::GetInstance(GetWorld());
	if (Subsystem)
	{
		Subsystem->UnlockAchievement(AchievementID);
	}
}

void UAchievementEditorSubsystem::ResetAllAchievements()
{
	UAchievementManagerSubsystem* Subsystem = UAchievementManagerSubsystem::GetInstance(GetWorld());
	if (!Subsystem)
	{
		return;
	}

	TArray<FAchievementAndProgress> Achievements = Subsystem->GetAchievementDefinitionsAndProgresses();
	for (const auto& [Definition, Progress] : Achievements)
	{
		if (Progress)
		{
			Progress->IsCompleted = false;
			Progress->ProgressValue = 0;
			UAchievementManagerSubsystem::SaveAchievementProgress(Progress);
		}
	}
}
