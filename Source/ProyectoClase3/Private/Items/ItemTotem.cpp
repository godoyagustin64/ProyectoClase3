// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/ItemTotem.h"

#include "Components/TotemActivationComponent.h"


// Sets default values
AItemTotem::AItemTotem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ActivationComponent = CreateDefaultSubobject<UTotemActivationComponent>(TEXT("ActivationComponent"));
	
}




// Called when the game starts or when spawned
void AItemTotem::BeginPlay()
{
	Super::BeginPlay();
	if (ActivationComponent)
	{
		ActivationComponent->OnActivationFinished.AddDynamic(this, &AItemTotem::HandleActivationFinished);
	}
}

void AItemTotem::HandleActivationFinished()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, TEXT("Totem terminó activación y envia broadcast"));
	OnTotemActivated.Broadcast();
}

// Called every frame
void AItemTotem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AItemTotem::Interact_Implementation(AActor* Actor)
{
	if (ActivationComponent)
	{
		ActivateTotemBP();
		ActivationComponent->StartActivation();
	}
}

