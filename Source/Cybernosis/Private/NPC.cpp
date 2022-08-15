// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC.h"

ANPC::ANPC()
{
	
	SetupStimulus();
}

void ANPC::SetupStimulus()
{
	Stimulus = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>(TEXT("Stimulus"));
	Stimulus->RegisterForSense(TSubclassOf<UAISense_Sight>());
	Stimulus->RegisterWithPerceptionSystem();
}
