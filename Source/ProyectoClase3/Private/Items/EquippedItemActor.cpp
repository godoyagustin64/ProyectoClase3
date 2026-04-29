#include "Items/EquippedItemActor.h"
#include "Components/StaticMeshComponent.h"

AEquippedItemActor::AEquippedItemActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;
}

void AEquippedItemActor::Initialize(UEquipmentItemData* ItemData)
{
	if (!ItemData) return;

	Mesh->SetStaticMesh(ItemData->ItemMesh);
}
