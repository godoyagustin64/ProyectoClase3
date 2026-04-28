#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Items/EquipmentTypes.h"
#include "Items/EquipmentItemData.h"
#include "EquipmentComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROYECTOCLASE3_API UEquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	void EquipItem(UEquipmentItemData* ItemData);

private:

	UPROPERTY()
	TMap<EEquipmentSlot, AActor*> EquippedActors;

	void UnequipSlot(EEquipmentSlot Slot);

	FName GetSocketName(EEquipmentSlot Slot) const;
};