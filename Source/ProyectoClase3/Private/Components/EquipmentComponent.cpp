#include "Components/EquipmentComponent.h"
#include "GameFramework/Character.h"

void UEquipmentComponent::EquipItem(UEquipmentItemData* ItemData)
{
	if (!ItemData) return;

	ACharacter* Char = Cast<ACharacter>(GetOwner());
	if (!Char) return;

	EEquipmentSlot Slot = ItemData->Slot;

	UnequipSlot(Slot);

	AActor* NewActor = GetWorld()->SpawnActor<AActor>(ItemData->EquipmentActorClass);

	FName Socket = GetSocketName(Slot);

	NewActor->SetActorEnableCollision(false);
	NewActor->AttachToComponent(
		Char->GetMesh(),
		FAttachmentTransformRules::SnapToTargetIncludingScale,
		Socket
	);

	EquippedActors.Add(Slot, NewActor);
}

void UEquipmentComponent::UnequipSlot(EEquipmentSlot Slot)
{
	if (EquippedActors.Contains(Slot))
	{
		EquippedActors[Slot]->Destroy();
		EquippedActors.Remove(Slot);
	}
}

FName UEquipmentComponent::GetSocketName(EEquipmentSlot Slot) const
{
	switch (Slot)
	{
	case EEquipmentSlot::Weapon: return "WeaponSocket";
	case EEquipmentSlot::Helmet: return "HeadSocket";
	case EEquipmentSlot::Chest: return "ChestSocket";
	}

	return NAME_None;
}