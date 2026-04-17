// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/ItemPuerta.h"
#include "Kismet/GameplayStatics.h"
#include "Items/ItemTotem.h"


// Sets default values
AItemPuerta::AItemPuerta()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	HojaIzquierda = CreateDefaultSubobject<UStaticMeshComponent>("HojaIzquierda");
	HojaDerecha = CreateDefaultSubobject<UStaticMeshComponent>("HojaDerecha");
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;
	
	HojaDerecha->SetupAttachment(RootComponent);
	HojaIzquierda->SetupAttachment(RootComponent);
}


void AItemPuerta::OnTotemActivated()
{
	ActivatedTotems++;

	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green,
		FString::Printf(TEXT("Activados: %d / %d"), ActivatedTotems, TotalTotems));

	if (ActivatedTotems == TotalTotems)
	{
		OpenDoor();
	}
}


bool bDoorOpened = false;


void AItemPuerta::OpenDoor()
{
	bDoorOpened = true;
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("PUERTA ABIERTA"));
	OpenDoorBP();
}



// Called when the game starts or when spawned
void AItemPuerta::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AItemTotem::StaticClass(), FoundActors);

	TotalTotems = FoundActors.Num();

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red,
		FString::Printf(TEXT("Total de totems: %d"), TotalTotems));

	for (AActor* Actor : FoundActors)
	{
		AItemTotem* Totem = Cast<AItemTotem>(Actor);

		if (Totem)
		{
			Totem->OnTotemActivated.AddDynamic(this, &AItemPuerta::OnTotemActivated);
		}
	}
}



// Called every frame
void AItemPuerta::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

