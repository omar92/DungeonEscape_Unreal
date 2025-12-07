// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Mover.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DUNGEONESCAPE_API UMover : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMover();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void Move(float DeltaTime);
	void Open();
	void Close();

private:
	UPROPERTY(EditAnywhere)
	bool DoMove = false;

	UPROPERTY(EditAnywhere)
	FVector Direction;

	UPROPERTY(EditAnywhere)
	float Speed = 1.f;

	UPROPERTY(EditAnywhere)
	float Distance = 100.f;

	UPROPERTY(EditAnywhere)
	bool bIsReturning = false;
	
	UPROPERTY(VisibleAnywhere)
	bool IsMoving = false;
	
	FVector StartLocation;
};
