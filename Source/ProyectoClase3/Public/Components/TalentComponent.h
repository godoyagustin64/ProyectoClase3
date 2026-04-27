// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TalentDataAsset.h"
#include "TalentComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROYECTOCLASE3_API UTalentComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UTalentComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	
	// 🔹 Puntos disponibles
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 SkillPoints = 0;

	// 🔹 Talentos disponibles
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<UTalentDataAsset*> TalentAssets;

	// 🔹 Nivel de cada talento
	UPROPERTY()
	TMap<UTalentDataAsset*, int32> TalentLevels;

	// 🔹 Función principal
	UFUNCTION(BlueprintCallable)
	void UpgradeTalent(UTalentDataAsset* Talent);
	
	UFUNCTION()
	void AddSkillPoint();

private:
	void ApplyTalentEffect(UTalentDataAsset* Talent);
	
};
