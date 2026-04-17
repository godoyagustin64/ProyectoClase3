// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/HealthComponent.h"


// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}




// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UHealthComponent::TakeDamage(float Damage)
{
	CurrentHealth -= Damage;
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Recibiste daño!"));
	OnHealthChanged.Broadcast(CurrentHealth);
}

void UHealthComponent::Heal(float Heal)
{
	CurrentHealth = FMath::Clamp(CurrentHealth + Heal, 0.f, MaxHealth);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Te curaste: "));
}