// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemData.h"
#include "EquipmentTypes.h"
#include "EquipmentItemData.generated.h"

class AEquipmentActor;

UCLASS(BlueprintType)
class PROYECTOCLASE3_API UEquipmentItemData : public UItemData
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UStaticMesh> ItemMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EEquipmentSlot Slot;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AActor> EquipmentActorClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AEquipmentActor> PickupActorClass;
};
