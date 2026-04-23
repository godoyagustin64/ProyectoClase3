// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "OrbeXP.generated.h"

UCLASS()
class PROYECTOCLASE3_API AOrbeXP : public AItemBase
{
	GENERATED_BODY()


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	AOrbeXP();
	
	void OnOrbeAgarrado(AActor* OtherActor);
	

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
