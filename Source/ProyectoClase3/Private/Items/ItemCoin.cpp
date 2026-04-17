// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/ItemCoin.h"


// Sets default values
AItemCoin::AItemCoin()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	RootComponent = SphereCollision;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AItemCoin::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItemCoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AItemCoin::Interact_Implementation(AActor* Actor)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Collected Coin"));	
	Destroy();
}

