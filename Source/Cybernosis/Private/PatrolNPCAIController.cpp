// Fill out your copyright notice in the Description page of Project Settings.


#include "PatrolNPCAIController.h"
#include "AIPoint.h"
#include "BehaviorTree/BehaviorTree.h"

void APatrolNPCAIController::BeginPlay()
{
	Super::BeginPlay();
	RunBehaviorTree(BehaviorTree);

}

void APatrolNPCAIController::SetStartPoint(AAIPoint* startPoint)
{
	StartPoint = startPoint;
}

void APatrolNPCAIController::SetEndPoint(AAIPoint* endPoint)
{
	EndPoint = endPoint;
}

void APatrolNPCAIController::StartPatrol()
{
	GetBlackboardComponent()->SetValueAsVector(TEXT("EndPoint"),EndPoint->GetActorLocation());
	GetBlackboardComponent()->SetValueAsVector(TEXT("StartPoint"), StartPoint->GetActorLocation());
}

