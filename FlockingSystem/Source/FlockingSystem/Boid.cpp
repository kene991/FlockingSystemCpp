// Fill out your copyright notice in the Description page of Project Settings.


#include "Boid.h"

#include "GeometryCollection/GeometryCollectionComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMath.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ABoid::ABoid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	VelocityVector = FVector:: ZeroVector;
}

// Called when the game starts or when spawned
void ABoid::BeginPlay()
{
	Super::BeginPlay();
	VelocityVector += FVector::One() * Speed;
}

FVector ABoid::BoundArea(FVector boid_position)
{
	FVector V = FVector::ZeroVector;

	if (boid_position.X < BoidManager->GetMinBounds().X + 10) 
		V.X = TurnSpeed;
	else if (boid_position.X > BoidManager->GetMaxBounds().X - 10)
		V.X = -TurnSpeed;

	if (boid_position.Y < BoidManager->GetMinBounds().Y + 10)
		V.Y = TurnSpeed;
	else if (boid_position.Y > BoidManager->GetMaxBounds().Y - 10)
		V.Y = -TurnSpeed;

	if (boid_position.Z < BoidManager->GetMinBounds().Z + 10)
		V.Z = TurnSpeed;
	else if (boid_position.Z > BoidManager->GetMaxBounds().Z - 10)
		V.Z = -TurnSpeed;

	return V;
}

void ABoid::SetSpeed(float speed)
{
	Speed = speed;	
}

void ABoid::SetTurnSpeed(float turnSpeed)
{
	TurnSpeed = turnSpeed;
}

void ABoid::SetDistance(float distance)
{
	Distance = distance;
}

void ABoid::SetAngleView(float angle)
{
	CosAngleView = angle;
}

FVector ABoid::GetVelocityVector()
{
	return VelocityVector;
}

void ABoid::SetVelocityVector(FVector v)
{
	VelocityVector = v;
}

void ABoid::LockInsideBounds()
{
	//Keeping the boids LOCKED inside the bounds
	FVector P = GetActorLocation();
	P.X = FMath::Clamp(P.X, BoidManager->GetMinBounds().X, BoidManager->GetMaxBounds().X);
	P.Y = FMath::Clamp(P.Y, BoidManager->GetMinBounds().Y ,BoidManager->GetMaxBounds().Y);
	P.Z = FMath::Clamp(P.Z, BoidManager->GetMinBounds().Z , BoidManager->GetMaxBounds().Z );
	SetActorLocation(P);
}

void ABoid::NeighborCheck(FVector Start)
{
	TArray<AActor*> BoidsNearBy;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABoid::StaticClass(), BoidsNearBy);

	Neighbor.Empty(); //clearing the list every tick
	
	for (AActor* Boid : BoidsNearBy)
	{
		if (Boid == this) continue;
		if (Boid == Cast<ABoid>(Boid))
		{
			//https://www.youtube.com/watch?v=ekNZW4vChwU
			FVector ToBoid = (Boid->GetActorLocation() - GetActorLocation());
			float dot = FMath::Cos(FVector::DotProduct(ToBoid.GetSafeNormal(), VelocityVector.GetSafeNormal()));
			
			if (FVector::Dist(Start, Boid->GetActorLocation()) < Distance && dot < CosAngleView)
			{
				Neighbor.Add(Cast<ABoid>(Boid));
			}
		}
	}
}

FVector ABoid::AlignmentCalculation(TArray<ABoid*> Neighbors)
{
	FVector V = FVector::ZeroVector;

	if (Neighbors.Num() > 0)
	{
		for (class ABoid* N : Neighbors)
		{
			if (N == this) continue;
			
			V = V + N->GetActorLocation();
		}

		V/=Neighbors.Num();

		return ((V - GetActorLocation())) * BoidManager->AlignmentWeight;
	}

	return  FVector::ZeroVector;
}

FVector ABoid::SeparationCalculation(TArray<ABoid*> Neighbors)
{
	FVector V = FVector::ZeroVector;
	
	if (Neighbors.Num() > 0)
	{
		for (class ABoid* N : Neighbors)
		{
			if (N == this) continue;
			
			V = V - (N->GetActorLocation() - GetActorLocation());
		}

		return V * BoidManager->SeparationWeight;
	}

	return FVector::ZeroVector;
}


// Called every frame
void ABoid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	SetActorLocation(GetActorLocation() + VelocityVector * DeltaTime);
	VelocityVector += BoundArea(GetActorLocation());
	VelocityVector += AlignmentCalculation(Neighbor);
	VelocityVector += SeparationCalculation(Neighbor);
	BoidManager->LimitSpeed(this);
	
	LockInsideBounds();
	FRotator NewRot = UKismetMathLibrary::MakeRotFromX(VelocityVector);
	SetActorRotation(NewRot);

	FVector Start = GetActorLocation();
	FVector End = (GetActorLocation() + VelocityVector.GetSafeNormal() * Distance);
	
	NeighborCheck(Start);
	DrawDebugDirectionalArrow(GetWorld(), Start, End, 1.f, FColor::Red);
}

