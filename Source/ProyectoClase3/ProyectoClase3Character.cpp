// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProyectoClase3Character.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "ProyectoClase3.h"
#include "Components/HealthComponent.h"
#include "DataWrappers/ChaosVDQueryDataWrappers.h"
#include "interfaces/InteractInterface.h"

AProyectoClase3Character::AProyectoClase3Character()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 500.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f;
	CameraBoom->bUsePawnControlRotation = true;

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
	
	HealthComponent = CreateDefaultSubobject<UHealthComponent>("HealthComponent");
	
	ExperienceComponent = CreateDefaultSubobject<UExperienceComponent>(TEXT("ExperienceComponent"));
	
	StatsComponent = CreateDefaultSubobject<UStatsComponent>(TEXT("StatsComponent"));
	
	TalentComponent = CreateDefaultSubobject<UTalentComponent>(TEXT("TalentComponent"));
	
	EquipmentComponent = CreateDefaultSubobject<UEquipmentComponent>("EquipmentComponent");
	
}


void AProyectoClase3Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AProyectoClase3Character::Move);
		EnhancedInputComponent->BindAction(MouseLookAction, ETriggerEvent::Triggered, this, &AProyectoClase3Character::Look);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AProyectoClase3Character::Look);
		
		// Interact
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &AProyectoClase3Character::InteractOtherActor);
	}
	else
	{
		UE_LOG(LogProyectoClase3, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void AProyectoClase3Character::BeginPlay()
{
	Super::BeginPlay();
	
	HealthComponent->OnHealthChanged.AddDynamic(this, &AProyectoClase3Character::OnRecieveDamage);
	if (ExperienceComponent)
	{
		ExperienceComponent->OnLevelUp.AddDynamic(this, &AProyectoClase3Character::HandleLevelUp);
	}
}


void AProyectoClase3Character::HandleLevelUp(int32 NewLevel)
{
	if (StatsComponent)
	{
		StatsComponent->HandleLevelUp(NewLevel);
	}

	if (TalentComponent)
	{
		TalentComponent->AddSkillPoint();
	}
	


	// Debug
	GEngine->AddOnScreenDebugMessage(
		-1,
		2.f,
		FColor::Green,
		FString::Printf(TEXT("Level Up! SkillPoints: %d"),
			TalentComponent ? TalentComponent->SkillPoints : 0)
	);
}


void AProyectoClase3Character::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	// route the input
	DoMove(MovementVector.X, MovementVector.Y);
}

void AProyectoClase3Character::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	// route the input
	DoLook(LookAxisVector.X, LookAxisVector.Y);
}

void AProyectoClase3Character::DoMove(float Right, float Forward)
{
	if (GetController() != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = GetController()->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, Forward);
		AddMovementInput(RightDirection, Right);
	}
}

void AProyectoClase3Character::DoLook(float Yaw, float Pitch)
{
	if (GetController() != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(Yaw);
		AddControllerPitchInput(Pitch);
	}
}

void AProyectoClase3Character::DoJumpStart()
{
	// signal the character to jump
	Jump();
}

void AProyectoClase3Character::DoJumpEnd()
{
	// signal the character to stop jumping
	StopJumping();
}

void AProyectoClase3Character::OrbeXPTaken()
{
	if (ExperienceComponent)
	{
		ExperienceComponent->AddExperience(120.f);

		GEngine->AddOnScreenDebugMessage(
			-1,
			2.f,
			FColor::Green,
			FString::Printf(TEXT("Level: %d | XP: %.0f"), 
				ExperienceComponent->Level,
				ExperienceComponent->CurrentXP)
		);
	}
}


void AProyectoClase3Character::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	OverlapActor = OtherActor;
}

void AProyectoClase3Character::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);
	OverlapActor = nullptr;
}


void AProyectoClase3Character::InteractOtherActor()
{
	if (OverlapActor && OverlapActor->Implements<UInteractInterface>())
	{
		IInteractInterface::Execute_Interact(OverlapActor, this);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("Objeto interactuable. Interactuando...")));
	}
}
	
void AProyectoClase3Character::OnRecieveDamage(float CurrentHealth)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("Se escuchó el evento desde el character y la vida actual es: %.2f"), (CurrentHealth)));
}
