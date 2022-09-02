// Fill out your copyright notice in the Description page of Project Settings.


#include "PatrolEnemy.h"
#include "PatrolAIController.h"

void APatrolEnemy::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Pawn Begin Play"));
	APatrolAIController* AIController = Cast<APatrolAIController>(GetController());
	if (AIController != nullptr)
	{
		AIController->SetEndPoint(EndPoint);
		AIController->SetStartPoint(StartPoint);
		AIController->StartPatrol();
	}
}

APatrolEnemy::APatrolEnemy()
{
	
}