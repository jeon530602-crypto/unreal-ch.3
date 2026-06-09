// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LaserTrap.generated.h"

UCLASS()
class CH3PROJECT_API ALaserTrap : public AActor
{
	GENERATED_BODY()
	
public:	
	ALaserTrap();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMeshComp;

	FVector StartLocation;

	bool bMovingUp = true;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MoveSpeed = 200.0f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MaxRange = 260.0f;
};
