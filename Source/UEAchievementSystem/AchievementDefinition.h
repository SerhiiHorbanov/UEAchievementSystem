// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AchievementDefinition.generated.h"

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
	float Value;
};
