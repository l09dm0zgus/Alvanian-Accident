// Fill out your copyright notice in the Description page of Project Settings.


#include "AlbanianPlayerMovementComponent.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"

void UAlbanianPlayerMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime))
    {
        return;
    }
    bIsMoving = false;
    FVector DesiredMovementThisFrame = ConsumeInputVector().GetClampedToMaxSize(1.0f) * DeltaTime * Speed;
    if (!DesiredMovementThisFrame.IsNearlyZero())
    {
        FHitResult Hit;
        SafeMoveUpdatedComponent(DesiredMovementThisFrame, UpdatedComponent->GetComponentRotation(), true, Hit);
        bIsMoving = true;
        if (Hit.IsValidBlockingHit())
        {
            StopMovementImmediately();
            bIsMoving = false;
        }
    }
      
}

void UAlbanianPlayerMovementComponent::Turn(float AxisValue)
{
    FVector MouseLocation, MouseDirection;
    FVector ActorLocation = UpdatedComponent->GetComponentLocation();
    UGameplayStatics::GetPlayerController(GetWorld(), 0)->DeprojectMousePositionToWorld(MouseLocation, MouseDirection);
    if (FVector::Dist2D(MouseLocation, ActorLocation) > DistanceToDisableRotating)
    {
        FRotator NewRotation = UKismetMathLibrary::FindLookAtRotation(ActorLocation, MouseLocation);
        UpdatedComponent->SetRelativeRotation(FRotator(0.0f, NewRotation.Yaw, 90.0f));
    }
   
    
}

bool UAlbanianPlayerMovementComponent::IsMoving()
{ 
    return bIsMoving;
}

