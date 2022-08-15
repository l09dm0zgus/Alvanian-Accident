// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCAIController.h"

ANPCAIController::ANPCAIController()
{

}

void ANPCAIController::BeginPlay()
{
	Super::BeginPlay();
	RunBehaviorTree(BehaviorTree);
}


UBlackboardComponent* ANPCAIController::GetBlackboardComponent()
{
	return BlackboardComponent;
}

void ANPCAIController::OnTargetDetected(AActor* Actor, FAIStimulus const Stimulus)
{
	if (auto const character = Cast<AAlbanianPlayer>(Actor))
	{
		BlackboardComponent->SetValueAsBool(TEXT("IsCanSeePlayer"), Stimulus.WasSuccessfullySensed());
		UE_LOG(LogTemp, Display, TEXT("See: %s"), BToS(Stimulus.WasSuccessfullySensed()))

	}
}

void ANPCAIController::SetupPerceptionSystem()
{
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Config Sight"));
	UAIPerceptionComponent *perceptionComponent =   CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AI Perception Config"));
	
	SightConfig->SightRadius = 150.0f;
	SightConfig->LoseSightRadius = SightConfig->SightRadius + 50.0f;
	SightConfig->PeripheralVisionAngleDegrees = 90.0f;
	SightConfig->SetMaxAge(5.0f);
	SightConfig->AutoSuccessRangeFromLastSeenLocation = 900.0f;
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	perceptionComponent->SetDominantSense(*SightConfig->GetSenseImplementation());
	perceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this,&ANPCAIController::OnTargetDetected);
	perceptionComponent->ConfigureSense(*SightConfig);

	SetPerceptionComponent(*perceptionComponent);
}
