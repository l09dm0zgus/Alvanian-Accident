// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "HealthComponent.h"
#include "PaperFlipbookComponent.h"

AEnemy::AEnemy()
{
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health"));
	SetupStimulus();
}

void AEnemy::SetupStimulus()
{
	Stimulus = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>(TEXT("Stimulus"));
	Stimulus->RegisterForSense(TSubclassOf<UAISense_Sight>());
    Stimulus->RegisterWithPerceptionSystem();
}


void AEnemy::BeginPlay()
{
    Super::BeginPlay();
    
}

void AEnemy::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
	if(!HealthComponent->IsDead())
	{
		if(GetCharacterMovement()->Velocity.Length() > 0.0f)
		{
			ChangeAnimation(WalkAnimation);
		}
		else
		{
			ChangeAnimation(IdleAnimation);
		}
	}
	else
	{
		Die();
	}
}

void AEnemy::Attack()
{
	
}

void AEnemy::Die()
{
	GetSprite()->SetLooping(false);
	ChangeAnimation(DeathAnimation);
	DetachFromControllerPendingDestroy();

}
void AEnemy::ChangeAnimation(UPaperFlipbook *Animation)
{
	GetSprite()->SetFlipbook(Animation);
	GetSprite()->Play();
}