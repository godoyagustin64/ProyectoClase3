// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TotemActivationComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnActivationFinished);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROYECTOCLASE3_API UTotemActivationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UTotemActivationComponent();
	
	void StartActivation();
	
	
	UPROPERTY(BlueprintAssignable)
	FOnActivationFinished OnActivationFinished;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	void FinishActivation();

	UPROPERTY(EditAnywhere)
	float ActivationTime = 3.0f;

	bool bIsActivated = false;

	FTimerHandle ActivationTimer;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
