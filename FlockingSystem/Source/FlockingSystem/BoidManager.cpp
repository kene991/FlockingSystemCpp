// Fill out your copyright notice in the Description page of Project Settings.


#include "BoidManager.h"

#include "Boid.h"

// Sets default values
ABoidManager::ABoidManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

FVector ABoidManager::GetMinBounds()
{
	return  FVector(Xmin,Ymin,Zmin);
}

FVector ABoidManager::GetMaxBounds()
{
	return  FVector(Xmax,Ymax,Zmax);
}

void ABoidManager::LimitSpeed(ABoid* boid)
{
	FVector V = FVector::ZeroVector;
	
	if (boid->GetVelocityVector().Size() > SpeedMax)
	{
		V = (boid->GetVelocityVector() / boid->GetVelocityVector().Size()) * SpeedMax;
		boid->SetVelocityVector(V);
	}
	else if (boid->GetVelocityVector().Size() < SpeedMin)
	{
		V = (boid->GetVelocityVector() / boid->GetVelocityVector().Size()) * SpeedMin;
		boid->SetVelocityVector(V);
	}
}

// Called when the game starts or when spawned
void ABoidManager::BeginPlay()
{
	Super::BeginPlay();
	CreateAvoidenceRays();
	CreateBoids();
}

TArray<FVector> ABoidManager::GetRaysVectors()
{
	return RayDirections;
}

float ABoidManager::GetMaxSpeed()
{
	return SpeedMax;
}

float ABoidManager::GetMinSpeed()
{
	return SpeedMin;
}

void ABoidManager::CreateAvoidenceRays()
{
	int GoldenRatio = (1 + FMath::Sqrt(5.0))/2;
	int GoldenAngle = PI * 2 *  GoldenRatio;

	for (int i = 0; i < NumberOfPoints; i++)
	{
		float t = (float)i / (NumberOfPoints);
		float inclination = FMath::Acos(1 - 2 * t);
		float azimuth = GoldenAngle * i;

		float x = FMath::Cos(azimuth) * FMath::Sin(inclination);
		float y = FMath::Sin(inclination) * FMath::Sin(azimuth);
		float z = FMath::Cos(inclination);
		FRotator Rotator = RotateOffset;

		RayDirections.Add(Rotator.RotateVector(FVector(x, y, z)));
	}
}

void ABoidManager::CreateBoids()
{
	FVector boundMin = FVector(Xmin, Ymin, Zmin);
	FVector boundMax = FVector(Xmax, Ymax, Zmax);
	FBox bounds = FBox(boundMin, boundMax); //creating a box Vector
	
	for (int i = 0; i < BoidCount; i++)
	{
		ABoid* Boid = GetWorld()->SpawnActor<ABoid>(BoidClass);
		Boid->BoidManager = this;
		Boid->SetDistance(BoidDistance);
		Boid->SetAngleView(BoidCosAngleView);
		Boid->SetActorLocation( FMath::RandPointInBox(bounds));
		Boid->SetSpeed(FMath::FRandRange(SpeedMin, SpeedMax));
		Boid->SetTurnSpeed(DefaultTurnSpeed);
	}
}

// Called every frame
void ABoidManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

