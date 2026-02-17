// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AchievementCompletionType.h"
#include "Engine/DataAsset.h"
#include "AchievementDefinition.generated.h"

enum class EAchievementCompletionType : uint8;

UCLASS()
class UEACHIEVEMENTSYSTEM_API UAchievementDefinition : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Achievement")
	FName ID;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Achievement")
	FText Name;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Achievement")
	FText Description;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Achievement")
	UTexture2D* Icon;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Achievement", 
		meta = (EditCondition = "CompletionType == EAchievementCompletionType::Counter", EditConidtionHides))
	int TargetValue;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Achievement")
	EAchievementCompletionType CompletionType;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Achievement")
	bool IsHidden;
};
