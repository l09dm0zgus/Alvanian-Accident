// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NPC.h"
#include "PatrolNPC.generated.h"

/**
 * 
 */
UCLASS()
class CYBERNOSIS_API APatrolNPC : public ANPC
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere)
	class AAIPoint* StartPoint;
	UPROPERTY(EditAnywhere)
	class AAIPoint* EndPoint;
protected:
	virtual void BeginPlay() override;
	APatrolNPC();
};
