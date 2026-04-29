#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EquipmentItemData.h"
#include "interfaces/InteractInterface.h"
#include "EquipmentActor.generated.h"

UCLASS()
class PROYECTOCLASE3_API AEquipmentActor : public AActor, public IInteractInterface
{
	GENERATED_BODY()

public:
	AEquipmentActor();

protected:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UEquipmentItemData* ItemData;
	
	void Initialize(UEquipmentItemData* NewItemData);
	
	virtual void Interact_Implementation(AActor* Actor) override;
};