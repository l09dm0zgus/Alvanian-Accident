// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
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
	class AAIPoint* StartPoint;
	UPROPERTY(EditAnywhere)
	class AAIPoint* EndPoint;
protected:
	virtual void BeginPlay() override;
	APatrolEnemy();
};
