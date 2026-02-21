#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AchievementEditorSubsystem.generated.h"

UCLASS(BlueprintType)
class UEACHIEVEMENTSYSTEMEDITOR_API UAchievementEditorSubsystem : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Achievements")
	void ForceUnlockAchievement(FName AchievementID);

	UFUNCTION(BlueprintCallable, Category = "Achievements")
	void ResetAllAchievements();
};
