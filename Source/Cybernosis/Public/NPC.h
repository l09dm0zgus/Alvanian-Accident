// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "NPC.generated.h"

/**
 * 
 */
UCLASS()
class CYBERNOSIS_API ANPC : public APaperCharacter
{
	GENERATED_BODY()
public:
	ANPC();
private:
	UAIPerceptionStimuliSourceComponent* Stimulus;
	void SetupStimulus();
};
