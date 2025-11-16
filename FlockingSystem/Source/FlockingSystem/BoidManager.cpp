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
		float Inclination = FMath::Acos(1 - 2 * t);
		float Azimuth = GoldenAngle * i;

		float x = FMath::Cos(Azimuth) * FMath::Sin(Inclination);
		float y = FMath::Sin(Inclination) * FMath::Sin(Azimuth);
		float z = FMath::Cos(Inclination);
		FRotator Rotator = RotateOffset;

		RayDirections.Add(Rotator.RotateVector(FVector(x, y, z)));
	}
}

void ABoidManager::AdjustBoidCount(int32 TargetCount)
{
	FVector BoundMin = FVector(Xmin, Ymin, Zmin);
	FVector BoundMax = FVector(Xmax, Ymax, Zmax);
	FBox Bounds = FBox(BoundMin, BoundMax); //creating a box Vector
	
	int32 CurrentCount = Boids.Num();

	// if I need more boids
	if (CurrentCount < TargetCount)
	{
		int32 ToSpawn = TargetCount - CurrentCount;
		for (int32 i = 0; i < ToSpawn; i++)
		{
			ABoid* Boid = GetWorld()->SpawnActor<ABoid>(BoidClass);
			Boid->BoidManager = this;
			Boid->SetActorLocation( FMath::RandPointInBox(Bounds));
			Boid->SetActorRotation(FMath::VRand().ToOrientationRotator());
			Boids.Add(Boid);
		}
	}
	// if too many boids are present
	else if (CurrentCount > TargetCount)
	{
		int32 ToRemove = CurrentCount - TargetCount;

		for (int32 i = 0; i < ToRemove; i++)
		{
			ABoid* B = Boids.Pop();  // removes last safely
			if (B)
				B->Destroy();
		}
	}
}

// Called every frame
void ABoidManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

