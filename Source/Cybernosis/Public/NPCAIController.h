// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#define BToS(b) b ? TEXT("true") : TEXT("false")

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionTypes.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "GameFramework/Character.h"
#include "Perception/AIPerceptionComponent.h"
#include "AlbanianPlayer.h"
#include "NPCAIController.generated.h"


/**
 * 
 */
UCLASS()
class CYBERNOSIS_API ANPCAIController : public AAIController
{
	GENERATED_BODY()
public:
	ANPCAIController();
	void BeginPlay() override;
	UBlackboardComponent* GetBlackboardComponent();
private:
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	UBehaviorTreeComponent* BehaviorTreeComponent;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	UBehaviorTree* BehaviorTree;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	UBlackboardComponent* BlackboardComponent;
	UAISenseConfig_Sight* SightConfig;
	UFUNCTION()
	void OnTargetDetected(AActor* Actor,FAIStimulus const Stimulus);
	void SetupPerceptionSystem();

};
