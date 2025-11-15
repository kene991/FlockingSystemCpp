// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoidManager.generated.h"

class ABoid;

UCLASS()
class FLOCKINGSYSTEM_API ABoidManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoidManager();

	FVector GetMinBounds();
	FVector GetMaxBounds();

	void CreateAvoidenceRays();
	TArray<FVector> GetRaysVectors();

	float GetMaxSpeed();
	float GetMinSpeed();

	UPROPERTY(EditAnywhere, Category="Boid Settings")
	bool ShowDebug;
	
	void LimitSpeed(ABoid* boid);

	UPROPERTY(EditAnywhere, Category="Rule Factor", meta=(ClampMin="0.0", ClampMax="1.0", UIMin="0.0", UIMax="1.0"))
	float CohesionWeight;

	UPROPERTY(EditAnywhere, Category="Rule Factor", meta=(ClampMin="0.0", ClampMax="1.0", UIMin="0.0", UIMax="1.0"))
	float SeparationWeight;

	UPROPERTY(EditAnywhere, Category="Rule Factor", meta=(ClampMin="0.0", ClampMax="1.0", UIMin="0.0", UIMax="1.0"))
	float AlignmentWeight;

	UPROPERTY(EditAnywhere, Category="Rule Factor", meta=(ClampMin="0.0", ClampMax="1.0", UIMin="0.0", UIMax="1.0"))
	float AvoidenceWeight;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category="Setup Boid")
	TSubclassOf<ABoid> BoidClass;

	UPROPERTY(EditAnywhere, Category="Setup Boid")
	int BoidCount;

	UPROPERTY(EditAnywhere, Category="Distance")
	float BoidDistance;

	UPROPERTY(EditAnywhere, Category="View Angle")
	float BoidCosAngleView;
	
	UPROPERTY(EditAnywhere, Category="Initialize Speed")
	float SpeedMin;

	UPROPERTY(EditAnywhere, Category="Initialize Speed")
	float SpeedMax;
	
	UPROPERTY(EditAnywhere, Category="Initialize Speed")
	int DefaultTurnSpeed;

	UPROPERTY(EditAnywhere, Category="Avoidance")
	int NumberOfPoints;

	UPROPERTY(EditAnywhere, Category="Bounds")
     int Xmin = -640;
	UPROPERTY(EditAnywhere, Category="Bounds")
	 int Xmax = 0;
	UPROPERTY(EditAnywhere, Category="Bounds")
     int Ymin = -1120;
    UPROPERTY(EditAnywhere, Category="Bounds")
	 int Ymax = -400;
	UPROPERTY(EditAnywhere, Category="Bounds")
     int Zmin = 10;
    UPROPERTY(EditAnywhere, Category="Bounds")
	 int Zmax = 370;
	
	UPROPERTY(EditAnywhere, Category="Boid Settings")
	FRotator RotateOffset;

	UPROPERTY(VisibleAnywhere, Category="Boid Settings")
	TArray<FVector> RayDirections;

	void CreateBoids();
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
