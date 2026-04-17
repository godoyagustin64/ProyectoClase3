// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Components/HealthComponent.h"
#include "GameFramework/Actor.h"
#include "DamageItem.generated.h"

UCLASS()
class PROYECTOCLASE3_API ADamageItem : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADamageItem();
	
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;
	
	UFUNCTION(BlueprintCallable)
	void AddDamage();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	
	UPROPERTY()
	FTimerHandle AreaDamageTimerHandle;
	
private:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UBoxComponent> BoxCollision;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UHealthComponent>HealthComponent;
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health", meta=(AllowPrivateAccess = "true"))
	float Damage = 10.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health", meta=(AllowPrivateAccess = "true"))
	float DamageCooldown = 2.0f;
	
};
