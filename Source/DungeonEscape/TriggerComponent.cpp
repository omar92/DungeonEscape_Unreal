// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"


UTriggerComponent::UTriggerComponent()
{
	OnComponentBeginOverlap.AddDynamic(this, &UTriggerComponent::OnOverlapBegins);
	OnComponentEndOverlap.AddDynamic(this, &UTriggerComponent::OnOverlapEnds);
}

void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay TriggerComponent on %s"), *GetOwner()->GetName());
	
	if (MoverActor)
	{
		Mover = MoverActor->FindComponentByClass<UMover>();
		if (!Mover)
		{
			UE_LOG(LogTemp, Warning, TEXT("Mover component not found on MoverActor %s in TriggerComponent on %s"), *MoverActor->GetName(), *GetOwner()->GetName());
			return;
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("MoverActor is not set in TriggerComponent on %s"), *GetOwner()->GetName());
	}
	
}

void UTriggerComponent::OnOverlapBegins(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!Mover) return;
	Mover->Open();
}

void UTriggerComponent::OnOverlapEnds(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (!Mover) return;
	Mover->Close();
}

