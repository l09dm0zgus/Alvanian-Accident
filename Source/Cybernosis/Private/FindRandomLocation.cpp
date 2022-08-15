// Fill out your copyright notice in the Description page of Project Settings.


#include "FindRandomLocation.h"

UFindRandomLocation::UFindRandomLocation()
{
	NodeName = TEXT("Find Random Location");
}

EBTNodeResult::Type UFindRandomLocation::ExecuteTask(UBehaviorTreeComponent& Owner, uint8* NodeMemory)
{
	auto const Controller = Cast<ANPCAIController>(Owner.GetAIOwner());
	auto const NPC = Controller->GetPawn();

	FVector const Origin = NPC->GetActorLocation();
	FNavLocation Location;
	UNavigationSystemV1* NavigationSystem = UNavigationSystemV1::GetCurrent(GetWorld());
	if (NavigationSystem->GetRandomPointInNavigableRadius(Origin, SearhRadius, Location))
	{
		Controller->GetBlackboardComponent()->SetValueAsVector(TEXT("TargetLocation"), Location.Location);
	}
	FinishLatentTask(Owner, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}
