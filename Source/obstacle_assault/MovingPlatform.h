// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLE_ASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Platform Translation")
	FVector TranslationVelocity = FVector(0, 0, 200);
	UPROPERTY(EditAnywhere, Category = "Platform Translation")
	double MoveDistance = 500.0;
	UPROPERTY(VisibleAnywhere, Category = "Platform Translation")
	double Distance = 0.0;

	UPROPERTY(EditAnywhere, Category = "Platform Rotation")
	FRotator RotationVelocity;

private:
	FVector InitialLocation;

	void Move(float DeltaTime);
	void Rotate(float DeltaTime);

	double GetDistanceMoved() const;
};
