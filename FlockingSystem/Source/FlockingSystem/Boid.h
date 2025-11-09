// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BoidManager.h"
#include "GameFramework/Actor.h"
#include "Boid.generated.h"

UCLASS()
class FLOCKINGSYSTEM_API ABoid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoid();

	void SetSpeed(float speed);
	void SetTurnSpeed(float turnSpeed);
	void SetDistance(float distance);
	void SetAngleView(float angle);

	FVector GetVelocityVector();
	void SetVelocityVector(FVector v);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FVector BoundArea(FVector boid_position);
	
private:

	UPROPERTY(VisibleAnywhere)
	TArray<class ABoid*> Neighbor;
	
	UPROPERTY(EditAnywhere)
	float Distance = 50;

	UPROPERTY(EditAnywhere)
	float CosAngleView;

	UPROPERTY(EditAnywhere)
	float Speed;

	UPROPERTY(EditAnywhere)
	float TurnSpeed;
	
	FVector VelocityVector;
	void LockInsideBounds();
	void NeighborCheck(FVector Start);

	FVector CohesionCalculation(TArray<ABoid*> Neighbors);
	FVector SeparationCalculation(TArray<ABoid*> Neighbors);
	FVector AlignmentCalculation(TArray<ABoid*> Neighbors);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	ABoidManager* BoidManager;

};
