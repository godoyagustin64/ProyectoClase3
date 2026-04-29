#include "Items/EquipmentActor.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Character.h"
#include "Components/EquipmentComponent.h"

AEquipmentActor::AEquipmentActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;

	Mesh->SetGenerateOverlapEvents(true);
}


void AEquipmentActor::BeginPlay()
{
	Super::BeginPlay();

	Initialize(ItemData);
}

void AEquipmentActor::Initialize(UEquipmentItemData* NewItemData)
{
	ItemData = NewItemData;

	if (ItemData && ItemData->ItemMesh)
	{
		Mesh->SetStaticMesh(ItemData->ItemMesh);
	}
}

void AEquipmentActor::Interact_Implementation(AActor* Actor)
{
	if (!Actor) return;

	UEquipmentComponent* EquipComp = Actor->FindComponentByClass<UEquipmentComponent>();
	if (!EquipComp) return;

	EquipComp->EquipItem(ItemData);

	Destroy();
}
