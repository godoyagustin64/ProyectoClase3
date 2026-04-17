// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "interfaces/InteractInterface.h"
#include "ItemBase.generated.h"

class UStaticMeshComponent;


UCLASS()
class PROYECTOCLASE3_API AItemBase : public AActor, public IInteractInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AItemBase();
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Components", meta=(AllowPrivateAccess="true"))
	TObjectPtr<class UStaticMeshComponent> Mesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	

	virtual void Interact_Implementation(AActor* Actor) override;
	
};