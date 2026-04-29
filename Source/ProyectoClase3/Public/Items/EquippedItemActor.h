#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EquipmentItemData.h"
#include "EquippedItemActor.generated.h"

UCLASS()
class PROYECTOCLASE3_API AEquippedItemActor : public AActor
{
	GENERATED_BODY()

public:

	AEquippedItemActor();

	void Initialize(UEquipmentItemData* ItemData);

protected:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;
};