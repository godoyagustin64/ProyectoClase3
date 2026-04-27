// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TalentDataAsset.generated.h"

UENUM(BlueprintType)
enum class ETalentEffectType : uint8
{
	Health,
	Damage,
	Speed
};
UCLASS()
class PROYECTOCLASE3_API UTalentDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

UPROPERTY(EditAnywhere, BlueprintReadOnly)
FName TalentID;

UPROPERTY(EditAnywhere, BlueprintReadOnly)
int32 MaxLevel = 1;

UPROPERTY(EditAnywhere, BlueprintReadOnly)
int32 CostPerLevel = 1;

UPROPERTY(EditAnywhere, BlueprintReadOnly)
ETalentEffectType EffectType;

UPROPERTY(EditAnywhere, BlueprintReadOnly)
float ValuePerLevel = 10.f;
};