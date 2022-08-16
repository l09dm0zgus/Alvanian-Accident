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
private:
	UPROPERTY(EditAnywhere)
	class UHealthComponent* HealthComponent;
	UAIPerceptionStimuliSourceComponent* Stimulus;
	void SetupStimulus();
};
