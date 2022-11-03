
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Enemy.generated.h"

/**
 * 
 */
UCLASS()
class CYBERNOSIS_API AEnemy: public APaperCharacter
{
	GENERATED_BODY()
public:
	AEnemy();
	void BeginPlay() override;
	void Tick(float DeltaTime) override;
	virtual void Attack();
private:
	UPROPERTY(EditAnywhere)
	class UHealthComponent* HealthComponent;
	UPROPERTY(EditAnywhere)
	class UPaperFlipbook *WalkAnimation;
	UPROPERTY(EditAnywhere)
	class UPaperFlipbook *IdleAnimation;
	UPROPERTY(EditAnywhere)
	class UPaperFlipbook *DeathAnimation;
	UAIPerceptionStimuliSourceComponent* Stimulus;
	void SetupStimulus();
	void Die();
	void ChangeAnimation(UPaperFlipbook *Animation);
};
