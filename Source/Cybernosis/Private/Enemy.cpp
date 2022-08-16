// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "HealthComponent.h"

AEnemy::AEnemy()
{
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health"));
	SetupStimulus();
}

void AEnemy::SetupStimulus()
{
	Stimulus = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>(TEXT("Stimulus"));
	Stimulus->RegisterForSense(TSubclassOf<UAISense_Sight>());
	Stimulus->RegisterWithPerceptionSystem();
}
