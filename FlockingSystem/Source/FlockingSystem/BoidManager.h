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
	
	UPROPERTY(EditAnywhere, Category="Boid Settings")
	bool ShowDirectionalDebug;
	
	UPROPERTY(EditAnywhere, Category="Boid Settings")
	bool disableZAxis;
	
	void LimitSpeed(ABoid* boid);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Rule Factor", meta=(ClampMin="0.0", ClampMax="1.0", UIMin="0.0", UIMax="1.0"))
	float CohesionWeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Rule Factor", meta=(ClampMin="0.0", ClampMax="1.0", UIMin="0.0", UIMax="1.0"))
	float SeparationWeight;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Rule Factor", meta=(ClampMin="0.0", ClampMax="1.0", UIMin="0.0", UIMax="1.0"))
	float AlignmentWeight;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Rule Factor", meta=(ClampMin="0.0", ClampMax="1.0", UIMin="0.0", UIMax="1.0"))
	float AvoidenceWeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Initialize Speed")
	float SpeedMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Initialize Speed")
	float SpeedMax;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Initialize Speed")
	int DefaultTurnSpeed;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Distance")
	float BoidDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="View Angle")
	float BoidCosAngleView;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Bounds")
	int Padding;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Boids")
	int32 MaxBoidCount = 300;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Boids")
	int32 MinBoidCount = 30;

	UFUNCTION(BlueprintCallable)
	void AdjustBoidCount(int32 TargetCount);
	
	float GetMaxSpeed();
	float GetMinSpeed();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category="Setup Boid")
	TSubclassOf<ABoid> BoidClass;

	UPROPERTY(EditAnywhere, Category="Setup Boid")
	int BoidCount;

	UPROPERTY(EditAnywhere, Category="Avoidance")
	int NumberOfPoints;

	UPROPERTY(EditAnywhere, Category="Bounds")
     int Xmin;
	UPROPERTY(EditAnywhere, Category="Bounds")
	 int Xmax;
	UPROPERTY(EditAnywhere, Category="Bounds")
     int Ymin;
    UPROPERTY(EditAnywhere, Category="Bounds")
	 int Ymax;
	UPROPERTY(EditAnywhere, Category="Bounds")
     int Zmin ;
    UPROPERTY(EditAnywhere, Category="Bounds")
	 int Zmax;
	
	UPROPERTY(EditAnywhere, Category="Boid Settings")
	FRotator RotateOffset;

	UPROPERTY(VisibleAnywhere, Category="Boid Settings")
	TArray<FVector> RayDirections;

	TArray<ABoid*> Boids;
	int32 lastCount;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
