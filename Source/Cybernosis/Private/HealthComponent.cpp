
#include "HealthComponent.h"

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::DamageTaken);
}

void UHealthComponent::SetCurrentHealth(float currentHealth)
{
	this->CurrentHealth = currentHealth;
}

void UHealthComponent::IncreaseCurrentHealth(float Value)
{
	CurrentHealth += Value;
}

void UHealthComponent::DecreaseCurrentHealth(float Value)
{
	CurrentHealth -= Value;
}

void UHealthComponent::SetStartHealth(float startHealth)
{
	this->StartHealth = startHealth;
}

float UHealthComponent::GetCurrentHealth()
{
	return CurrentHealth;
}

float UHealthComponent::GetStartHealth()
{
	return StartHealth;
}

void UHealthComponent::DamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamegeType, AController* Instigator, AActor* DamageCauser)
{
	UE_LOG(LogTemp, Warning, TEXT("Actor Damaged"))
	CurrentHealth -= Damage;
	if (CurrentHealth <= 0.00)
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor died"))
	}
}


