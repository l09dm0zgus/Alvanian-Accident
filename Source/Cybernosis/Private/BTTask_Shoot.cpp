// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Shoot.h"
#include "Enemy.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "AIController.h"

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComponent,uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComponent,NodeMemory);
    AEnemy *Enemy = Cast<AEnemy>(OwnerComponent.GetAIOwner()->GetCharacter());
    if(Enemy)
    {
        Enemy->Attack();
    }
    return EBTNodeResult::Succeeded;
    
}

UBTTask_Shoot::UBTTask_Shoot()
{
    NodeName = "Shoot";
}


