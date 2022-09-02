// Fill out your copyright notice in the Description page of Project Settings.


#include "AlbanianPlayerCameraComponent.h"

UAlbanianPlayerCameraComponent::UAlbanianPlayerCameraComponent()
{

}

void UAlbanianPlayerCameraComponent::ZoomIn(float AxisValue)
{
	
	if (GetComponentLocation().Z >= MinimalZoomDistance)
	{
		SetWorldLocation(FVector(GetComponentLocation().X, GetComponentLocation().Y, GetComponentLocation().Z + AxisValue));
	}
}

void UAlbanianPlayerCameraComponent::ZoomOut(float AxisValue)
{
	if (GetComponentLocation().Z <= MaximalZoomDistance)
	{
		SetWorldLocation(FVector(GetComponentLocation().X, GetComponentLocation().Y, GetComponentLocation().Z + AxisValue));
	}
}

void UAlbanianPlayerCameraComponent::PinchZoom(float AxisValue)
{
	if (AxisValue != 1.0)
	{
		if (AxisValue < 1.0f)
		{
			ZoomOut(ZoomOutAxisValue);
		}
		if (AxisValue > 1.0f)
		{
			ZoomIn(ZoomInAxisValue);
		}
	}
	
}




