// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "PaperSpriteComponent.h"
#include "Projectile.generated.h"

UCLASS()
class CYBERNOSIS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AProjectile();
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
	virtual void BeginPlay() override;
private:
	void CreateAndSetupProjectileComponent();
	void CreateAndSetupSpriteComponent();
	UPROPERTY(EditAnywhere)
	USphereComponent* CollisionComponent;
	UPROPERTY(EditAnywhere)
	UProjectileMovementComponent* ProjectileMovement;
	UPROPERTY(EditAnywhere)
	UPaperSpriteComponent* SpriteComponent;
	UPROPERTY(EditAnywhere)
	float Damage = 15.0f;
};
