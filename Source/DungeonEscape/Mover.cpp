// Fill out your copyright notice in the Description page of Project Settings.


#include "Mover.h"


// Sets default values for this component's properties
UMover::UMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMover::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetOwner()->GetActorLocation();
}


// Called every frame
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	Move(DeltaTime);
}

//Executes a move if ShouldDoAMove is true then sets ShouldDoAMove to false when the move is complete
void UMover::Move(float DeltaTime) 
{
	if (!DoMove && !IsMoving) return;

	IsMoving = true;
	FVector CurrentLocation = GetOwner()->GetActorLocation();
	FVector TargetLocation;

	if (!bIsReturning)
	{
		TargetLocation = StartLocation + (Direction.GetSafeNormal() * Distance);
	}
	else
	{
		TargetLocation = StartLocation;
	}

	FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, Speed);
	GetOwner()->SetActorLocation(NewLocation);

	if (FVector::Dist(NewLocation, TargetLocation) <= 1.f)
	{
		IsMoving = false;
		DoMove = false;
	}
}


void UMover::Open()
{
	bIsReturning = false;
	DoMove = true;
}

void UMover::Close()
{
	bIsReturning = true;
	DoMove = true;
}
