// Fill out your copyright notice in the Description page of Project Settings.


#include "PatrolAIController.h"
#include "AIPoint.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

void APatrolAIController::BeginPlay()
{
	Super::BeginPlay();
	RunBehaviorTree(BehaviorTree);

}

void APatrolAIController::SetStartPoint(AAIPoint* startPoint)
{
	StartPoint = startPoint;
}

void APatrolAIController::SetEndPoint(AAIPoint* endPoint)
{
	EndPoint = endPoint;
}

void APatrolAIController::StartPatrol()
{
	GetBlackboardComponent()->SetValueAsVector(TEXT("EndPoint"),EndPoint->GetActorLocation());
	GetBlackboardComponent()->SetValueAsVector(TEXT("StartPoint"), StartPoint->GetActorLocation());
}

