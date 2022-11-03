// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CYBERNOSIS_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UHealthComponent();

protected:
	virtual void BeginPlay() override;
	UFUNCTION()
	void DamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamegeType, AController* Instigator, AActor* DamageCauser);
private:

	UPROPERTY(EditAnywhere, Category = "Health")
	float StartHealth = 100.0f;

	UPROPERTY(EditAnywhere, Category = "Health")
	float CurrentHealth = 100.0f;
	bool bIsDead = false;
public:
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetCurrentHealth();
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetStartHealth();
		UFUNCTION(BlueprintCallable, Category = "Health")
	void SetCurrentHealth(float Health);
	UFUNCTION(BlueprintCallable, Category = "Health")
	void IncreaseCurrentHealth(float Value);
	UFUNCTION(BlueprintCallable, Category = "Health")
	void DecreaseCurrentHealth(float Value);
	UFUNCTION(BlueprintCallable, Category = "Health")
	void SetStartHealth(float Health);
	bool IsDead();
};
