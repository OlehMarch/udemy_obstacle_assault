// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	InitialLocation = GetActorLocation();

	UE_LOG(LogTemp, Display, TEXT("BeginPlay: %s"), *GetName());
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move(DeltaTime);
	Rotate(DeltaTime);
}

void AMovingPlatform::Move(float DeltaTime)
{
	Distance = GetDistanceMoved();

	if (Distance > MoveDistance)
	{
		UE_LOG(LogTemp, Display, TEXT("%s overshot by: %f"), *GetName(), Distance - MoveDistance);

		FVector MoveLocation = TranslationVelocity.GetSafeNormal();
		InitialLocation += MoveLocation * MoveDistance;
		SetActorLocation(InitialLocation);
		TranslationVelocity = -TranslationVelocity;
	}
	else
	{
		FVector Location = GetActorLocation();
		Location += TranslationVelocity * DeltaTime;
		SetActorLocation(Location);
	}
}

void AMovingPlatform::Rotate(float DeltaTime)
{
	AddActorLocalRotation(RotationVelocity * DeltaTime);
}

double AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Distance(InitialLocation, GetActorLocation());
}
