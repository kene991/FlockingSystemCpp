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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<ABoid> BoidClass;

	UPROPERTY(EditAnywhere)
	int BoidCount;

	UPROPERTY(EditAnywhere)
	int DefaultTurnSpeed;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
