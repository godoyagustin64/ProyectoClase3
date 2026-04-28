#pragma once

#include "CoreMinimal.h"
#include "EquipmentTypes.generated.h"

UENUM(BlueprintType)
enum class EEquipmentSlot : uint8
{
	Weapon UMETA(DisplayName="Weapon"),
	Helmet UMETA(DisplayName="Helmet"),
	Chest UMETA(DisplayName="Chest")
};