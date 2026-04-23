// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/OrbeXP.h"

#include "ProyectoClase3Character.h"


class UExperienceComponent;
// Sets default values
AOrbeXP::AOrbeXP()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

void AOrbeXP::OnOrbeAgarrado(AActor* OtherActor)
{
	if (AProyectoClase3Character* Player = Cast<AProyectoClase3Character>(OtherActor))
	{
		if (UExperienceComponent* XPComp = Player->FindComponentByClass<UExperienceComponent>())
		{
			XPComp->AddExperience(50.f);
			Destroy();
		}
	}
}

// Called when the game starts or when spawned
void AOrbeXP::BeginPlay()
{
	Super::BeginPlay();
	
}



// Called every frame
void AOrbeXP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AOrbeXP::NotifyActorBeginOverlap(AActor* Actor)
{
	OnOrbeAgarrado(Actor);
}

