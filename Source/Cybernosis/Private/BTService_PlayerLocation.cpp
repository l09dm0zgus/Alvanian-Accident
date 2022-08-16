// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLocation.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_PlayerLocation::UBTService_PlayerLocation()
{
	NodeName = "Update Player Location";
}

void UBTService_PlayerLocation::TickNode(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComponent, NodeMemory, DeltaSeconds);
	OwnerComponent.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), UGameplayStatics::GetPlayerPawn(GetWorld(), 0)->GetActorLocation());
}
