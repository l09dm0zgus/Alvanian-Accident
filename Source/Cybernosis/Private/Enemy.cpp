// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

AEnemy::AEnemy()
{
	
	SetupStimulus();
}

void AEnemy::SetupStimulus()
{
	Stimulus = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>(TEXT("Stimulus"));
	Stimulus->RegisterForSense(TSubclassOf<UAISense_Sight>());
	Stimulus->RegisterWithPerceptionSystem();
}
