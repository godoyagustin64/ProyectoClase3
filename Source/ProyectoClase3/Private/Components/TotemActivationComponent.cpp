// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/TotemActivationComponent.h"
#include "TimerManager.h"
#include "Engine/World.h"


// Sets default values for this component's properties
UTotemActivationComponent::UTotemActivationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UTotemActivationComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTotemActivationComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                              FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTotemActivationComponent::StartActivation()
{
	if (bIsActivated)
	{
		return;
	}
	
	bIsActivated = true;
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, TEXT("Activando Totem..."));

	GetWorld()->GetTimerManager().SetTimer(
		ActivationTimer,
		this,
		&UTotemActivationComponent::FinishActivation,
		ActivationTime,
		false);
	
}


void UTotemActivationComponent::FinishActivation()
{
	bIsActivated = true;

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, TEXT("TOTEM ACTIVADO"));

	OnActivationFinished.Broadcast();
}


