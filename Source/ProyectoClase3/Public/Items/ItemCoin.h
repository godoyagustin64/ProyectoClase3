// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "interfaces/InteractInterface.h"
#include "Components/SphereComponent.h"
#include "ItemCoin.generated.h"

UCLASS()
class PROYECTOCLASE3_API AItemCoin : public AActor, public IInteractInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AItemCoin();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
virtual void Interact_Implementation(AActor* Actor) override;
	
	
private:


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<USphereComponent> SphereCollision;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> Mesh; 
	
};


