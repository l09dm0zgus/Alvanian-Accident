// Fill out your copyright notice in the Description page of Project Settings.


#include "PatrolNPC.h"
#include "PatrolNPCAIController.h"

void APatrolNPC::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Pawn Begin Play"));
	APatrolNPCAIController* AIController = Cast<APatrolNPCAIController>(GetController());
	if (AIController != nullptr)
	{
		AIController->SetEndPoint(EndPoint);
		AIController->SetStartPoint(StartPoint);
		AIController->StartPatrol();
	}
}

APatrolNPC::APatrolNPC()
{
	
}
