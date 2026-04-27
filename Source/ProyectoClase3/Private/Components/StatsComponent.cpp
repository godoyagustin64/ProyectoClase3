// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/StatsComponent.h"


// Sets default values for this component's properties
UStatsComponent::UStatsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UStatsComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

// Fórmulas
float UStatsComponent::GetMaxHealth() const
{
	return 100.f + (Strength * 10.f) + BonusHealth;
}

float UStatsComponent::GetDamage() const
{
	return 10.f + (Strength * 2.f) + BonusDamage;
}

// 🔹 Qué pasa al subir de nivel
void UStatsComponent::HandleLevelUp(int32 NewLevel)
{
	// Escalado simple (después lo mejoramos)
	Strength += 2;
	Agility += 1;
	Intelligence += 1;
}

// Called every frame
void UStatsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

