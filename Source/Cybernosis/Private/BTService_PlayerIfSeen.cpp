// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerIfSeen.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "PatrolAIController.h"
UBTService_PlayerIfSeen::UBTService_PlayerIfSeen()
{
	NodeName = "Update If Player seen";
}

void UBTService_PlayerIfSeen::TickNode(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory, float DeltaSeconds)
{
	if (OwnerComponent.GetAIOwner()->LineOfSightTo(UGameplayStatics::GetPlayerPawn(GetWorld(), 0)))
	{
		OwnerComponent.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(), true);
	}
	else
	{
		OwnerComponent.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	}
	
}
