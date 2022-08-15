// Fill out your copyright notice in the Description page of Project Settings.


#include "FindPlayerLocation.h"

UFindPlayerLocation::UFindPlayerLocation()
{
	NodeName = TEXT("Find Player Location");
}

EBTNodeResult::Type UFindPlayerLocation::ExecuteTask(UBehaviorTreeComponent& Owner, uint8* NodeMemory)
{
	const APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	auto const Controller = Cast<ANPCAIController>(Owner.GetAIOwner());
	UE_LOG(LogTemp, Display, TEXT("HERE!"))

	const FVector PlayerLocation = Player->GetActorLocation();
	if (bIsSearchRandom)
	{
		FNavLocation Location;
		UNavigationSystemV1* NavigationSystem = UNavigationSystemV1::GetCurrent(GetWorld());
		if (NavigationSystem->GetRandomPointInNavigableRadius(PlayerLocation, SearhRadius, Location))
		{
			Controller->GetBlackboardComponent()->SetValueAsVector(TEXT("TargetLocation"), Location.Location);
			UE_LOG(LogTemp,Display,TEXT("HERE!"))
		}
	}
	else
	{
		Controller->GetBlackboardComponent()->SetValueAsVector(TEXT("TargetLocation"), PlayerLocation);
		UE_LOG(LogTemp, Display, TEXT("HERE!"))
	}
	FinishLatentTask(Owner, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}
