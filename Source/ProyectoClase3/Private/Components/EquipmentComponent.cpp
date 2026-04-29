#include "Components/EquipmentComponent.h"
#include "GameFramework/Character.h"
#include "Items/EquippedItemActor.h"
#include "Items/EquipmentActor.h"

void UEquipmentComponent::EquipItem(UEquipmentItemData* ItemData)
{
	if (!ItemData) return;

	ACharacter* Char = Cast<ACharacter>(GetOwner());
	if (!Char) return;

	EEquipmentSlot Slot = ItemData->Slot;

	// 👇 1. DROPEAR SI YA HAY ALGO
	if (EquippedItems.Contains(Slot))
	{
		DropItem(Slot);
	}

	// 👇 2. REMOVER VISUAL ANTERIOR
	UnequipSlot(Slot);

	// 👇 3. SPAWNEAR NUEVO VISUAL
	AEquippedItemActor* NewActor =
	GetWorld()->SpawnActor<AEquippedItemActor>(
		ItemData->EquipmentActorClass
	);
	NewActor->Initialize(ItemData);

	// 🚨 IMPORTANTE: sin colisión
	NewActor->SetActorEnableCollision(false);

	// 👇 4. ATTACH
	FName Socket = GetSocketName(Slot);

	NewActor->AttachToComponent(
		Char->GetMesh(),
		FAttachmentTransformRules::SnapToTargetIncludingScale,
		Socket
	);

	// 👇 5. GUARDAR
	EquippedActors.Add(Slot, NewActor);
	EquippedItems.Add(Slot, ItemData);
}

void UEquipmentComponent::DropItem(EEquipmentSlot Slot)
{
	if (!EquippedItems.Contains(Slot)) return;

	ACharacter* Char = Cast<ACharacter>(GetOwner());
	if (!Char) return;

	UEquipmentItemData* ItemData = EquippedItems[Slot];

	if (!ItemData || !ItemData->PickupActorClass) return;

	FVector Forward = Char->GetActorForwardVector();
	FVector SpawnLocation = Char->GetActorLocation() + Forward * 100.f;

	FActorSpawnParameters Params;
	Params.Owner = nullptr;

	AEquipmentActor* Pickup = GetWorld()->SpawnActor<AEquipmentActor>(
		ItemData->PickupActorClass,
		SpawnLocation,
		FRotator::ZeroRotator,
		Params
	);

	if (Pickup)
	{
		// 👇 MUY IMPORTANTE
		Pickup->Initialize(ItemData);
	}
}

void UEquipmentComponent::UnequipSlot(EEquipmentSlot Slot)
{
	if (EquippedActors.Contains(Slot))
	{
		EquippedActors[Slot]->Destroy();
		EquippedActors.Remove(Slot);
		EquippedItems.Remove(Slot);
	}
}

FName UEquipmentComponent::GetSocketName(EEquipmentSlot Slot) const
{
	switch (Slot)
	{
	case EEquipmentSlot::Weapon:
		return "WeaponSocket";

	case EEquipmentSlot::Helmet:
		return "HeadSocket";

	case EEquipmentSlot::Chest:
		return "ChestSocket";
	}

	return NAME_None;
}