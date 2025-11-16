// Fill out your copyright notice in the Description page of Project Settings.


#include "Boid.h"

#include "GeometryCollection/GeometryCollectionComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMath.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ABoid::ABoid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//VelocityVector = FVector:: ZeroVector;
}

// Called when the game starts or when spawned
void ABoid::BeginPlay()
{
	Super::BeginPlay();
}

FVector ABoid::BoundArea(FVector boid_position)
{
	FVector V = FVector::ZeroVector;

	if (boid_position.X < BoidManager->GetMinBounds().X + BoidManager->Padding) 
		V.X = TurnSpeed;
	else if (boid_position.X > BoidManager->GetMaxBounds().X - BoidManager->Padding)
		V.X = -TurnSpeed;

	if (boid_position.Y < BoidManager->GetMinBounds().Y + BoidManager->Padding)
		V.Y = TurnSpeed;
	else if (boid_position.Y > BoidManager->GetMaxBounds().Y - BoidManager->Padding)
		V.Y = -TurnSpeed;

	if (boid_position.Z < BoidManager->GetMinBounds().Z + BoidManager->Padding)
		V.Z = TurnSpeed;
	else if (boid_position.Z > BoidManager->GetMaxBounds().Z - BoidManager->Padding)
		V.Z = -TurnSpeed;

	return V;
}

FVector ABoid::GetVelocityVector()
{
	return VelocityVector;
}

void ABoid::SetVelocityVector(FVector v)
{
	VelocityVector = v;
}

void ABoid::UpdateBoidVariables()
{
	this->TurnSpeed = BoidManager->DefaultTurnSpeed;
	this->Distance = BoidManager->BoidDistance;
	this->CosAngleView= BoidManager->BoidCosAngleView;
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


FVector ABoid::FindClearDirection()
{
	FVector BestDir = GetActorForwardVector();
	float FurthestUnobstructedDist =	0.0f;
	FHitResult Hit;
	ECollisionChannel SenseChannel = ECC_GameTraceChannel1;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this); // Ignore the actor performing the trace

	for (int i = 0; i <BoidManager->GetRaysVectors().Num(); i++)
	{
		FVector LocalDir = BoidManager->GetRaysVectors()[i];
		FVector WorldDir = GetTransform().GetRotation().RotateVector(LocalDir);
		bool DirHit = GetWorld()->LineTraceSingleByChannel(Hit, GetActorLocation(), GetActorLocation() + WorldDir * Distance, SenseChannel,  QueryParams);

		//https://www.youtube.com/watch?v=ekNZW4vChwU
		float Dot = FVector::DotProduct(WorldDir.GetSafeNormal(), GetActorForwardVector().GetSafeNormal());
		
		if ((Dot < CosAngleView))
		{
			if (!DirHit)
			{
				// Perfect clear direction, return immediately
				if (BoidManager->ShowDirectionalDebug)
					DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + WorldDir * Distance, FColor::Green, false, -1.0f, 0, 1.5f);
				
				// no obstacle in view radius
				return WorldDir * BoidManager->GetMaxSpeed() * BoidManager->AvoidenceWeight;
			}
			else
			{
				//if we hit something
				if (Hit.Distance > FurthestUnobstructedDist)
				{
					BestDir = WorldDir;
					FurthestUnobstructedDist = Hit.Distance;

					if (BoidManager->ShowDirectionalDebug)
					{
					DrawDebugLine(GetWorld(), GetActorLocation(), Hit.ImpactPoint, FColor::Red, false, -1.0f, 0, 1.5f);
					DrawDebugSphere(GetWorld(), Hit.ImpactPoint, 8.0f, 12, FColor::Red, false, -1.0f, 0, 1.0f);
					}
			}
			}
	}
		}
				//return the direction away from the obstacle
				return BestDir * BoidManager->GetMaxSpeed() * BoidManager->AvoidenceWeight; 
}


FVector ABoid::SeparationCalculation(TArray<ABoid*> Neighbors)
{
	FVector V = FVector::ZeroVector;

	for (class ABoid* N : Neighbors)
	{
		if (N == this) continue;
			
		V += (GetActorLocation() - N->GetActorLocation());
	}

	if (Neighbors.Num() > 0)
	{
		return V * BoidManager->SeparationWeight;
	}

	return FVector::ZeroVector;
}

FVector ABoid::AlignmentCalculation(TArray<ABoid*> Neighbors)
{
	FVector V = FVector::ZeroVector;
	
	if (Neighbors.Num() > 0)
	{
	for (class ABoid* N : Neighbors)
	{
		if (N == this) continue;
		V += N->GetVelocityVector().GetSafeNormal();
	}
		
		V/=Neighbors.Num();
		return ((V.GetSafeNormal() - VelocityVector.GetSafeNormal())) * BoidManager->AlignmentWeight * BoidManager->GetMinSpeed();
	}

	return FVector::ZeroVector;
}

FVector ABoid::CohesionCalculation(TArray<ABoid*> Neighbors)
{
	FVector V = FVector::ZeroVector;

	for (class ABoid* N : Neighbors)
	{
		if (N == this) continue;
			
		V += N->GetActorLocation();
	}

	if (Neighbors.Num() > 0)
	{
		V/=Neighbors.Num();
		return ((V - GetActorLocation())) * BoidManager->CohesionWeight;
	}

	return  FVector::ZeroVector;
}

// Called every frame
void ABoid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateBoidVariables();
	
	NeighborCheck(GetActorLocation());
	
	if (BoidManager->AvoidenceWeight > 0.0f)
		VelocityVector += FindClearDirection();

	if (VelocityVector.IsNearlyZero())
	{
		VelocityVector = GetActorForwardVector() * BoidManager->GetMaxSpeed();
	}

	VelocityVector += AlignmentCalculation(Neighbor);
	VelocityVector += CohesionCalculation(Neighbor);
	VelocityVector += SeparationCalculation(Neighbor);

	VelocityVector +=  BoundArea(GetActorLocation());
	
	BoidManager->LimitSpeed(this);

	SetActorLocation(GetActorLocation() + VelocityVector * DeltaTime);
	
	LockInsideBounds();
	
	FRotator NewRot = UKismetMathLibrary::MakeRotFromX(VelocityVector);
	SetActorRotation(NewRot);

	if (BoidManager->ShowDirectionalDebug)
	{
		FVector Start = GetActorLocation();
		FVector End = (GetActorLocation() + VelocityVector.GetSafeNormal() * Distance);
		DrawDebugDirectionalArrow(GetWorld(), Start, End, 1.f, FColor::Red);
	}
}

