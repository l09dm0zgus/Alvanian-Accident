// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "PaperSpriteComponent.h"
#include "AlbanianPlayerMovementComponent.h"
#include "AlbanianPlayerCameraComponent.h"
#include "HealthComponent.h"
#include "EyesLightComponent.h"
#include "WeaponComponent.h"
#include "PlayerHUD.h"
#include "PaperFlipbookComponent.h"
#include "AlbanianPlayer.generated.h"


UENUM(BlueprintType)
enum Weapon
{
	NO_WEAPON = 0    UMETA(DisplayName = "NO_WEAPON"),
	FIRST_WEAPON	 UMETA(DisplayName = "FIRST_WEAPON"),
	SECOND_WEAPON    UMETA(DisplayName = "SECOND_WEAPON"),
	MEELE_WEAPON     UMETA(DisplayName = "MEELE_WEAPON"),
};
UCLASS()
class CYBERNOSIS_API AAlbanianPlayer : public APawn
{
	GENERATED_BODY()

public:
	AAlbanianPlayer();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	Weapon CurrentWeapon;

	UPROPERTY(EditAnywhere)
	UAlbanianPlayerMovementComponent* MovementComponent;

	UPROPERTY(EditAnywhere)
	UAlbanianPlayerCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
	UPaperFlipbookComponent* FlipbookComponent;

	UPROPERTY(EditAnywhere)
	UPaperFlipbook* FistWeaponAnimation;

	UPROPERTY(EditAnywhere)
	UPaperFlipbook* SecondWeaponAnimation;

	UPROPERTY(EditAnywhere)
	UPaperFlipbook* ThirdWeaponAnimation;

	UPROPERTY(EditAnywhere)
	USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere)
	UEyesLightComponent* EyesLightComponent;

	UPROPERTY(EditAnywhere)
	UHealthComponent* HealthComponent;

	UPROPERTY(EditAnywhere)
	UWeaponComponent* FirstWeaponComponent;

	UPROPERTY(EditAnywhere)
	UWeaponComponent* SecondWeaponFirstGunComponent;


	UPROPERTY(EditAnywhere)
	UWeaponComponent* SecondWeaponSecondGunComponent;

	UPROPERTY(EditAnywhere)
	UCapsuleComponent* CapsuleComponent;

	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void Turn(float AxisValue);
	void Fire();
	void CreateAndSetupSpringArmComponent();
	void CreateAndSetupCameraComponent();
	void CreateAndSetupMovementComponent();
	void CreateAndSetupFlipbookComponent();
	void CreateAndSetupEyesLightComponent();
	void CreateAndSetupHealthComponent();
	void CreateAndSetupWeaponsComponents();
	void SetupLightFlare();
	void SetupFirstEyeLight();
	void SetupSecondEyeLight();
	void RollActor(float Angle);
	void ChooseFistWeapon();
	void ChooseSecondWeapon();
	void ChooseThirdWeapon();
};

