// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/TalentComponent.h"
#include "Components/StatsComponent.h"



UTalentComponent::UTalentComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UTalentComponent::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Warning, TEXT("Talents cargados: %d"), TalentAssets.Num());

	// Inicializar niveles en 0
	for (UTalentDataAsset* Talent : TalentAssets)
	{
		if (Talent)
		{
			TalentLevels.Add(Talent, 0);
		}
	}
}

void UTalentComponent::UpgradeTalent(UTalentDataAsset* Talent)
{
	if (!Talent || SkillPoints <= 0) return;

	int32& CurrentLevel = TalentLevels.FindOrAdd(Talent);

	if (CurrentLevel >= Talent->MaxLevel)
		return;

	if (SkillPoints < Talent->CostPerLevel)
		return;

	CurrentLevel++;
	SkillPoints -= Talent->CostPerLevel;

	ApplyTalentEffect(Talent);
}

void UTalentComponent::AddSkillPoint()
{
	SkillPoints++;
}

void UTalentComponent::ApplyTalentEffect(UTalentDataAsset* Talent)
{
	if (UStatsComponent* Stats = GetOwner()->FindComponentByClass<UStatsComponent>())
	{
		switch (Talent->EffectType)
		{
		case ETalentEffectType::Health:
			Stats->BonusHealth += Talent->ValuePerLevel;
			UE_LOG(LogTemp, Warning, TEXT("BonusHealth: %f"),
			Stats->BonusHealth);
			break;

		case ETalentEffectType::Damage:
			Stats->BonusDamage += Talent->ValuePerLevel;
			break;
			
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("Aplicando talento: %s"),
	*Talent->TalentID.ToString());
	

}



