// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemTotem.h"
#include "GameFramework/Actor.h"
#include "ItemPuerta.generated.h"

class UStaticMeshComponent;
class USceneComponent;

UCLASS()
class PROYECTOCLASE3_API AItemPuerta : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AItemPuerta();
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> HojaIzquierda;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> HojaDerecha;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	TObjectPtr<USceneComponent> Root;
	
	UPROPERTY(EditAnywhere)
	TArray<AItemTotem*> Totems;

	UFUNCTION()
	void OnTotemActivated();

	UFUNCTION()
	void OpenDoor();
	
	UFUNCTION(BlueprintImplementableEvent)
	void OpenDoorBP();
	
	int TotalTotems = 0;
	int ActivatedTotems = 0;

	bool bDoorOpened = false;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
