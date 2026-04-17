// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/DamageItem.h"

#include "Components/BoxComponent.h"
#include "Components/HealthComponent.h"


// Sets default values
ADamageItem::ADamageItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	
	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	RootComponent = BoxCollision;
	BoxCollision->SetLineThickness(5);
	BoxCollision->SetBoxExtent(FVector(150,150,150));
	BoxCollision->SetHiddenInGame(false);

}

void ADamageItem::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	if (IsValid(OtherActor))
	{
		HealthComponent = OtherActor->FindComponentByClass<UHealthComponent>();
		if (HealthComponent)
		{
			AddDamage();
			GetWorldTimerManager().SetTimer(
			AreaDamageTimerHandle,
			this,
			&ADamageItem::AddDamage,
			DamageCooldown,
			true
			);
			
		}	
	}
}

void ADamageItem::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);
	GetWorldTimerManager().ClearTimer(AreaDamageTimerHandle);
	HealthComponent = nullptr;
	
}

void ADamageItem::AddDamage()
{
	if (HealthComponent)
	{
		HealthComponent->TakeDamage(Damage);
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("Daño recibido: %.2f"), (Damage)));
	}
}

// Called when the game starts or when spawned
void ADamageItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADamageItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
};

