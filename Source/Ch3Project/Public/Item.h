// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class CH3PROJECT_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AItem();

protected:
	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, Category = "Rotation")
	float RotationSpeed = 90.0f;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
