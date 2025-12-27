// Fill out your copyright notice in the Description page of Project Settings.


#include "Lock.h"

// Sets default values
ALock::ALock()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Tags.Add(*KeyTag);

	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(RootComp);

	TriggerComponent = CreateDefaultSubobject<UTriggerComponent>(TEXT("TriggerComponent"));
	TriggerComponent->SetupAttachment(RootComp); // Attach to root
	//TriggerComponent->ActivatorTags.Add(*KeyTag);// Add the key tag to activator tags

	KeyItemMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("KeyItemMeshComponent"));
	KeyItemMeshComponent->SetupAttachment(RootComp); // Attach to root
}

// Called when the game starts or when spawned
void ALock::BeginPlay()
{
	Super::BeginPlay();
	SetIsKeyPlaced(false);
	
}

// Called every frame
void ALock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALock::SetIsKeyPlaced(bool bPlaced)
{
	IsKeyPlaced = bPlaced;
	TriggerComponent->Trigger(bPlaced);
	KeyItemMeshComponent->SetVisibility(bPlaced);
	
}

bool ALock::GetIsKeyPlaced()
{
	return IsKeyPlaced;
}
