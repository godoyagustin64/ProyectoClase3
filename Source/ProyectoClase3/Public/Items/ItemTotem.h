// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "Components/TotemActivationComponent.h"
#include "GameFramework/Actor.h"
#include "ItemTotem.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTotemActivated);

UCLASS()
class PROYECTOCLASE3_API AItemTotem : public AItemBase


{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AItemTotem();
	
	UPROPERTY(BlueprintAssignable)
	FOnTotemActivated OnTotemActivated;
	
	UFUNCTION(BlueprintImplementableEvent)
	void ActivateTotemBP();

	UPROPERTY(VisibleAnywhere)
	UTotemActivationComponent* ActivationComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void HandleActivationFinished();


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void Interact_Implementation(AActor* Actor) override;
	
	
	
};
