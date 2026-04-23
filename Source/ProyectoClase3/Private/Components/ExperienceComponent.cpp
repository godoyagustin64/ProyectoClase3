// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/ExperienceComponent.h"


// Sets default values for this component's properties
UExperienceComponent::UExperienceComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UExperienceComponent::AddExperience(float Amount)
{
	CurrentXP += Amount;

	OnXPChanged.Broadcast(CurrentXP, NextLevelXP);
	GEngine->AddOnScreenDebugMessage(
			-1,
			3.f,
			FColor::Green,
			FString::Printf(TEXT("Level: %d | XP: %.0f"), 
				Level,
				CurrentXP));

	while (CurrentXP >= NextLevelXP)
	{
		CurrentXP -= NextLevelXP;
		LevelUp();
	}
}

void UExperienceComponent::LevelUp()
{
	Level++;
	SkillPoints++;

	NextLevelXP = CalculateXPRequirement(Level);

	OnLevelUp.Broadcast(Level);
	
	GEngine->AddOnScreenDebugMessage(
	-1,
	2.f,
	FColor::Yellow,
	FString::Printf(TEXT("LEVEL UP! New Level: %d"), Level));
}

float UExperienceComponent::CalculateXPRequirement(int32 InLevel) const
{
	return 100.f * FMath::Pow(InLevel, 1.5f);
}



// Called when the game starts
void UExperienceComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UExperienceComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                         FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

