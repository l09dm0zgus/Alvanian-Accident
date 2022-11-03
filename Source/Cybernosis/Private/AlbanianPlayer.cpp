
#include "AlbanianPlayer.h"

AAlbanianPlayer::AAlbanianPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	CreateAndSetupFlipbookComponent();
	CreateAndSetupSpringArmComponent();
	CreateAndSetupCameraComponent();
	CreateAndSetupMovementComponent();
	CreateAndSetupEyesLightComponent();
	CreateAndSetupHealthComponent();
	CreateAndSetupWeaponsComponents();

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

void AAlbanianPlayer::BeginPlay()
{
	Super::BeginPlay();
	CurrentWeapon = NO_WEAPON;
}



void AAlbanianPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AAlbanianPlayer::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AAlbanianPlayer::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &AAlbanianPlayer::Turn);
	PlayerInputComponent->BindAction("FirstWeapon", IE_Pressed, this, &AAlbanianPlayer::ChooseFistWeapon);
	PlayerInputComponent->BindAction("SecondWeapon", IE_Pressed, this, &AAlbanianPlayer::ChooseSecondWeapon);
	PlayerInputComponent->BindAction("ThirdWeapon", IE_Pressed, this, &AAlbanianPlayer::ChooseThirdWeapon);
	PlayerInputComponent->BindAction("Shoot", IE_Pressed, this, &AAlbanianPlayer::Fire);
	PlayerInputComponent->BindAxis("ZoomIn", Camera, &UAlbanianPlayerCameraComponent::ZoomIn);
	PlayerInputComponent->BindAxis("ZoomOut", Camera, &UAlbanianPlayerCameraComponent::ZoomOut);
}

void AAlbanianPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(!HealthComponent->IsDead())
	{
		if (MovementComponent->IsMoving())
		{
			ChangeAnimation(LegsWalkAnimation,TopWalkAnimation,true);
		} 
		else
		{
			ChangeAnimation(LegsIdleAnimation,TopIdleAnimation,true);
		}
	}
	else
	{
		Die();
	}
}

void AAlbanianPlayer::MoveForward(float AxisValue)
{
	if (MovementComponent && (MovementComponent->UpdatedComponent == RootComponent))
	{
		MovementComponent->AddInputVector(GetActorForwardVector() * AxisValue);
	}
}

void AAlbanianPlayer::MoveRight(float AxisValue)
{
	if (MovementComponent && (MovementComponent->UpdatedComponent == RootComponent))
	{
		MovementComponent->AddInputVector(GetActorUpVector() * AxisValue);
	}
}

void AAlbanianPlayer::Turn(float AxisValue)
{
	if (MovementComponent && (MovementComponent->UpdatedComponent == RootComponent))
	{
		MovementComponent->Turn(AxisValue);
	}
}

void AAlbanianPlayer::Fire()
{
	switch (CurrentWeapon)
	{
		case FIRST_WEAPON:
			FirstWeaponComponent->Fire();
		break;
		case SECOND_WEAPON:
			SecondWeaponFirstGunComponent->Fire();
			SecondWeaponSecondGunComponent->Fire();
		break;
		default:
		break;
	}
}

void AAlbanianPlayer::CreateAndSetupSpringArmComponent()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraAttachmentArm"));
	SpringArm->SetupAttachment(TopFlipbookComponent);
	SpringArm->SetUsingAbsoluteRotation(true);
	SpringArm->TargetArmLength = 10.0f;
	
}

void AAlbanianPlayer::CreateAndSetupCameraComponent()
{
	Camera = CreateDefaultSubobject<UAlbanianPlayerCameraComponent>(TEXT("ActualCamera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
}

void AAlbanianPlayer::CreateAndSetupMovementComponent()
{
	MovementComponent = CreateDefaultSubobject<UAlbanianPlayerMovementComponent>(TEXT("MovementComponent"));
	MovementComponent->UpdatedComponent = RootComponent;
}

void AAlbanianPlayer::CreateAndSetupFlipbookComponent()
{
	TopFlipbookComponent = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("TopFlipbook"));
	TopFlipbookComponent->SetLooping(false);
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	TopFlipbookComponent->SetupAttachment(CapsuleComponent);
	LegsFlipbookComponent = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("LegsFlipbook"));
	LegsFlipbookComponent->SetupAttachment(TopFlipbookComponent);
	RootComponent = CapsuleComponent;
}

void AAlbanianPlayer::CreateAndSetupEyesLightComponent()
{
	EyesLightComponent = CreateDefaultSubobject<UEyesLightComponent>(TEXT("PlayerEyesLights"));
	EyesLightComponent->AttachToComponent(TopFlipbookComponent, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
	SetupLightFlare();
	SetupFirstEyeLight();
	SetupSecondEyeLight();
}

void AAlbanianPlayer::CreateAndSetupHealthComponent()
{
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health"));
}

void AAlbanianPlayer::CreateAndSetupWeaponsComponents()
{
	FirstWeaponComponent = CreateDefaultSubobject<UWeaponComponent>(TEXT("First Weapon"));
	FirstWeaponComponent->SetupAttachment(TopFlipbookComponent);
	FirstWeaponComponent->SetRelativeLocation(FVector(10.0f, -5.0f, -12.5f));

	SecondWeaponFirstGunComponent = CreateDefaultSubobject<UWeaponComponent>(TEXT("Second Weapon 1"));
	SecondWeaponFirstGunComponent->SetupAttachment(TopFlipbookComponent);
	SecondWeaponFirstGunComponent->SetRelativeLocation(FVector(10.0f, -5.0f, -9.0f));

	SecondWeaponSecondGunComponent = CreateDefaultSubobject<UWeaponComponent>(TEXT("Second Weapon 2"));
	SecondWeaponSecondGunComponent->SetupAttachment(TopFlipbookComponent);
	SecondWeaponSecondGunComponent->SetRelativeLocation(FVector(10.0f, -5.0f, 9.0f));
}

void AAlbanianPlayer::SetupLightFlare()
{
	FTransform Transform;
	FRotator Rotator;
	Rotator.Roll = -180.0f;
	Rotator.Yaw = 10.0f;
	Rotator.Pitch = 10.0f;
	Transform.SetRotation(Rotator.Quaternion());
	Transform.SetLocation(FVector(-41.0f, -20.0f, -8.5f));
	EyesLightComponent->SetupLightFlare(Transform, FLinearColor(1.0f, 0.0f, 0.0f), 18.0f, 5000.0f);

}

void AAlbanianPlayer::SetupFirstEyeLight()
{
	FTransform Transform;
	FRotator Rotator;
	Rotator.Roll = -70.0f;
	Rotator.Yaw = 90.0f;
	Transform.SetRotation(Rotator.Quaternion());
	Transform.SetLocation(FVector(1.9f, -12.5f, -1.6f));
	EyesLightComponent->SetupFirstEyeLight(Transform, FLinearColor(1.0f, 0.0f, 0.0f), 4.0f, 100000.0f);
}

void AAlbanianPlayer::SetupSecondEyeLight()
{
	FTransform Transform;
	FRotator Rotator;
	Rotator.Roll = -70.0f;
	Rotator.Yaw = 90.0f;
	Transform.SetRotation(Rotator.Quaternion());
	Transform.SetLocation(FVector(2.15f, -12.5, 3.0f));
	EyesLightComponent->SetupSecondEyeLight(Transform, FLinearColor(1.0f, 0.0f, 0.0f), 4.0f, 100000.0f);
}

void AAlbanianPlayer::RollActor(float Angle)
{
	FRotator NewRotation = GetActorRotation();
	NewRotation.Roll = Angle;
	SetActorRotation(NewRotation);
}

void AAlbanianPlayer::ChooseFistWeapon()
{
	TopFlipbookComponent->SetLooping(false);
	TopFlipbookComponent->SetFlipbook(FistWeaponAnimation);
	TopFlipbookComponent->Play();
	CurrentWeapon = FIRST_WEAPON;
}

void AAlbanianPlayer::ChooseSecondWeapon()
{
	TopFlipbookComponent->SetLooping(false);
	TopFlipbookComponent->SetFlipbook(SecondWeaponAnimation);
	TopFlipbookComponent->Play();
	CurrentWeapon = SECOND_WEAPON;
}

void AAlbanianPlayer::ChooseThirdWeapon()
{
	TopFlipbookComponent->SetLooping(false);
	TopFlipbookComponent->SetFlipbook(ThirdWeaponAnimation);
	TopFlipbookComponent->PlayFromStart();
	TopFlipbookComponent->ReverseFromEnd();
	CurrentWeapon = MEELE_WEAPON;

}


void AAlbanianPlayer::Die()
{
	CurrentWeapon = NO_WEAPON;
	ChangeAnimation(LegsIdleAnimation,DeathAnimation,false);
	DetachFromControllerPendingDestroy();

}
void AAlbanianPlayer::ChangeAnimation(UPaperFlipbook *LegsAnimation, UPaperFlipbook *TopAnimation, bool bIsLooping)
{
	if (CurrentWeapon == NO_WEAPON)
	{
		TopFlipbookComponent->SetLooping(bIsLooping);
		TopFlipbookComponent->SetFlipbook(TopAnimation);
		TopFlipbookComponent->Play();
	}
	LegsFlipbookComponent->SetFlipbook(LegsAnimation);
	LegsFlipbookComponent->Play();

}