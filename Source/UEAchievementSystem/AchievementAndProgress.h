// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AchievementAndProgress.generated.h"

class UAchievementDefinition;
class UAchievementProgress;

USTRUCT(BlueprintType)
struct FAchievementAndProgress
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Achievement")
	const UAchievementDefinition* Definition = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Achievement")
	UAchievementProgress* Progress = nullptr;
};
