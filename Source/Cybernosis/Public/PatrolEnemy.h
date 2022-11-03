
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "WeaponComponent.h"
#include "PatrolEnemy.generated.h"

/**
 *
 */
UCLASS()
class CYBERNOSIS_API APatrolEnemy : public AEnemy
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere)
	class AAIPoint *StartPoint;
	UPROPERTY(EditAnywhere)
	class AAIPoint *EndPoint;
	UPROPERTY(EditAnywhere)
	class UWeaponComponent *WeaponComponent;

protected:
	virtual void BeginPlay() override;
	APatrolEnemy();

public:
	void Attack() override;
};
