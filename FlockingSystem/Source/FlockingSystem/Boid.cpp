// Fill out your copyright notice in the Description page of Project Settings.


#include "Boid.h"
#include "Math/UnrealMath.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ABoid::ABoid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetVelocitySpeed = FVector:: ZeroVector;
}

// Called when the game starts or when spawned
void ABoid::BeginPlay()
{
	Super::BeginPlay();
	
}

FVector ABoid::BoundArea(FVector boid_position)
{
	FVector V = FVector::ZeroVector;

	if (boid_position.X < Xmin)
		V.X = 10;
	else if (boid_position.X > Xmax)
		V.X = -10;

	if (boid_position.Y < Ymin)
		V.Y = 10;
	else if (boid_position.Y > Ymax)
		V.Y = -10;

	if (boid_position.Z < Zmin)
		V.Z = 10;
	else if (boid_position.Z > Zmax)
		V.Z = -10;

	return V;
}

// Called every frame
void ABoid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	SetActorLocation(GetActorLocation() + SetVelocitySpeed * DeltaTime);
	SetVelocitySpeed += BoundArea(GetActorLocation());
	

	FRotator NewRot = UKismetMathLibrary::MakeRotFromX(SetVelocitySpeed);
	SetActorRotation(NewRot);

}

