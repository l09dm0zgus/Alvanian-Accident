// Fill out your copyright notice in the Description page of Project Settings.


#include "AIPoint.h"

AAIPoint::AAIPoint()
{
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SetRootComponent(SceneComponent);
}

void AAIPoint::BeginPlay()
{
	Super::BeginPlay();
	
}



