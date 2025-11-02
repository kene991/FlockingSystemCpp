// Fill out your copyright notice in the Description page of Project Settings.


#include "BoidManager.h"

#include "Boid.h"

// Sets default values
ABoidManager::ABoidManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABoidManager::BeginPlay()
{
	Super::BeginPlay();

	int Xmin = -640, Xmax = 0;
	int Ymin = -1120, Ymax = -400;
	int Zmin = 10, Zmax = 370;
	
	FVector boundMin = FVector(-640, -1120, 10);
	FVector boundMax = FVector(0, -400, 370);
	FBox bounds = FBox(boundMin, boundMax); //creating a box Vector
	
	for (int i = 0; i < BoidCount; i++)
	{
		ABoid* Boid = GetWorld()->SpawnActor<ABoid>(BoidClass);
		Boid->BoidManager = this;
		Boid->SetActorLocation( FMath::RandPointInBox(bounds));
		Boid->SetSpeed(FMath::FRandRange(-120.0f, 120.0f));
		Boid->SetTurnSpeed(DefaultTurnSpeed);
	}
	
}

// Called every frame
void ABoidManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

