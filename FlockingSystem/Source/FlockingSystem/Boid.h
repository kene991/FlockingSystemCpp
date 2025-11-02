// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Boid.generated.h"

UCLASS()
class FLOCKINGSYSTEM_API ABoid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoid();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FVector BoundArea(FVector boid_position);
	
private:	

	UPROPERTY(EditAnywhere)
	FVector SetVelocitySpeed;

	UPROPERTY(EditAnywhere)
	float obstacleAvoidRadius = 10;

	int Xmin = -640, Xmax = 0;
	int Ymin = -1120, Ymax = -400;
	int Zmin = 10, Zmax = 370;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
