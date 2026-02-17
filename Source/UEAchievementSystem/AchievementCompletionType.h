// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AchievementCompletionType.generated.h"

UENUM(BlueprintType)
enum class EAchievementCompletionType : uint8
{
	Boolean,
	Counter,
};
