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

void AEquipmentActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	ACharacter* Char = Cast<ACharacter>(OtherActor);
	if (!Char) return;

	UEquipmentComponent* EquipComp = Char->FindComponentByClass<UEquipmentComponent>();
	if (!EquipComp) return;

	EquipComp->EquipItem(ItemData);

	Destroy();
}
