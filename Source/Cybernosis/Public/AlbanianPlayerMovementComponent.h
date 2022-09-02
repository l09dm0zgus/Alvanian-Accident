// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "AlbanianPlayerMovementComponent.generated.h"

UCLASS()
class CYBERNOSIS_API UAlbanianPlayerMovementComponent : public UPawnMovementComponent
{
	GENERATED_BODY()
public:
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void Turn(float AxisValue);
	bool IsMoving();
private:
	UPROPERTY(EditAnywhere)
	float Speed = 150.0f;
	bool bIsMoving = false;
	UPROPERTY(EditAnywhere)
	float DistanceToDisableRotating = 0.5f;
};
