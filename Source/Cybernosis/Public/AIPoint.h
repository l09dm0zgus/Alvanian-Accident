// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AIPoint.generated.h"

UCLASS()
class CYBERNOSIS_API AAIPoint : public AActor
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere)
	class USceneComponent* SceneComponent;
public:	
	AAIPoint();
protected:
	virtual void BeginPlay() override;
};
