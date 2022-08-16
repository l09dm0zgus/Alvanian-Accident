// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "PaperSprite.h"
#include "Kismet/GameplayStatics.h"
AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = false;
	CreateAndSetupProjectileComponent();
	CreateAndSetupSpriteComponent();

	InitialLifeSpan = 5.0f;
}

void AProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	auto MyOwner = GetOwner();
	if (MyOwner == nullptr)
	{
		return;
	}
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherActor->Tags.Num() > 0) && (OtherActor->Tags[0] == FName(TEXT("Creature"))))
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *OtherActor->GetActorNameOrLabel())
		UGameplayStatics::ApplyDamage(OtherActor, Damage, MyOwner->GetInstigatorController(), this, UDamageType::StaticClass());
		Destroy();
	}
}

void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	SpriteComponent->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
}



void AProjectile::CreateAndSetupProjectileComponent()
{
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Component"));
	ProjectileMovement->UpdatedComponent = CollisionComponent;
	ProjectileMovement->InitialSpeed = 500.f;
	ProjectileMovement->MaxSpeed = 500.f;
	ProjectileMovement->ProjectileGravityScale = 0.0f;
	ProjectileMovement->bShouldBounce = true;

}

void AProjectile::CreateAndSetupSpriteComponent()
{
	SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite Component"));
	
	static ConstructorHelpers::FObjectFinder<UPaperSprite> ProjectileSprite (TEXT("/Game/sprites/Projectile/Projectile"));
	if (ProjectileSprite.Succeeded())
	{
		SpriteComponent->SetSprite(ProjectileSprite.Object);
		SpriteComponent->SetRelativeScale3D(FVector(0.1f, 0.1f, 0.1f));
	}
	RootComponent = SpriteComponent;
}



