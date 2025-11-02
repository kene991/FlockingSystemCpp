// Fill out your copyright notice in the Description page of Project Settings.


#include "Boid.h"
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

	if (boid_position.X < Xmin)
		V.X = TurnSpeed;
	else if (boid_position.X > Xmax)
		V.X = -TurnSpeed;

	if (boid_position.Y < Ymin)
		V.Y = TurnSpeed;
	else if (boid_position.Y > Ymax)
		V.Y = -TurnSpeed;

	if (boid_position.Z < Zmin)
		V.Z = TurnSpeed;
	else if (boid_position.Z > Zmax)
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

// Called every frame
void ABoid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	SetActorLocation(GetActorLocation() + VelocityVector * DeltaTime);
	VelocityVector += BoundArea(GetActorLocation());
	

	FRotator NewRot = UKismetMathLibrary::MakeRotFromX(VelocityVector);
	SetActorRotation(NewRot);

}

