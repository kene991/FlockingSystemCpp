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
	
	if (boid->GetVelocityVector().Size() > speedMax)
	{
		V = (boid->GetVelocityVector() / boid->GetVelocityVector().Size()) * speedMax;
		boid->SetVelocityVector(V);
	}
	else if (boid->GetVelocityVector().Size() < speedMin)
	{
		V = (boid->GetVelocityVector() / boid->GetVelocityVector().Size()) * speedMin;
		boid->SetVelocityVector(V);
	}
}

// Called when the game starts or when spawned
void ABoidManager::BeginPlay()
{
	Super::BeginPlay();
	
	FVector boundMin = FVector(Xmin, Ymin, Zmin);
	FVector boundMax = FVector(Xmax, Ymax, Zmax);
	FBox bounds = FBox(boundMin, boundMax); //creating a box Vector
	
	for (int i = 0; i < BoidCount; i++)
	{
		ABoid* Boid = GetWorld()->SpawnActor<ABoid>(BoidClass);
		Boid->BoidManager = this;
		Boid->SetDistance(boidDistance);
		Boid->SetAngleView(boidCosAngleView);
		Boid->SetActorLocation( FMath::RandPointInBox(bounds));
		Boid->SetSpeed(FMath::FRandRange(speedMin, speedMax));
		Boid->SetTurnSpeed(DefaultTurnSpeed);
	}
}


// Called every frame
void ABoidManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	

}

