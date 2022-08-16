// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_PlayerIfSeen.generated.h"

/**
 * 
 */
UCLASS()
class CYBERNOSIS_API UBTService_PlayerIfSeen : public UBTService_BlackboardBase
{
	GENERATED_BODY()
public:
	UBTService_PlayerIfSeen();
	void TickNode(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory, float DeltaSeconds) override;


};
