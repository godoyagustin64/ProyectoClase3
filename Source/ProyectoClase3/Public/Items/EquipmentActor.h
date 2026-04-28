#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EquipmentItemData.h"
#include "EquipmentActor.generated.h"

UCLASS()
class PROYECTOCLASE3_API AEquipmentActor : public AActor
{
	GENERATED_BODY()

public:
	AEquipmentActor();

protected:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	UEquipmentItemData* ItemData;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};