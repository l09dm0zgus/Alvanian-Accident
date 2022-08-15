// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NPCAIController.h"
#include "PatrolNPCAIController.generated.h"

/**
 * 
 */
UCLASS()
class CYBERNOSIS_API APatrolNPCAIController : public AAIController
{
	GENERATED_BODY()
private:
	class AAIPoint* StartPoint;
	class AAIPoint* EndPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	UBehaviorTree* BehaviorTree;
public:
	virtual void BeginPlay() override;
	void SetStartPoint(class AAIPoint* startPoint);
	void SetEndPoint(class AAIPoint* endPoint);
	void StartPatrol();
};
