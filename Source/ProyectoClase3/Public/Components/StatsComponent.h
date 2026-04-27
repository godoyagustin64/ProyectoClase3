// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StatsComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROYECTOCLASE3_API UStatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UStatsComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
	// ATRIBUTOS BASE
	// Fuerza
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
	int32 Strength = 5;
	
	// Agilidad
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
	int32 Agility = 5;
	
	// Inteligencia
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
	int32 Intelligence = 5;

	// Modificadores (para talentos, buffs, etc)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
	float BonusHealth = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
	float BonusDamage = 0.f;

	// Getters (stats calculados)
	UFUNCTION(BlueprintCallable)
	float GetMaxHealth() const;

	UFUNCTION(BlueprintCallable)
	float GetDamage() const;

	// Reacción al level up
	void HandleLevelUp(int32 NewLevel);
};
