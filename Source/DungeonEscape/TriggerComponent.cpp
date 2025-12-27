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

bool UTriggerComponent::IsActorActivator(const AActor* OtherActor)
{
	bool bIsActivator = false;
	for (const FName& Tag : ActivatorTags)
	{
		if (OtherActor->ActorHasTag(Tag))
		{
			return true;
		}
	}
	return false;
}

void UTriggerComponent::OnOverlapBegins(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor) return;
	if (!Mover) return;
	if (!IsActorActivator(OtherActor)) return;

	if (OverlapCount >= 255)
	{
		//log
		UE_LOG(LogTemp, Warning, TEXT("OverlapCount overflow in TriggerComponent on %s"), *GetOwner()->GetName());
		return;
		// prevent overflow
	}

	OverlapCount++;
	Trigger(true);
}

void UTriggerComponent::OnOverlapEnds(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (!OtherActor) return;
	if (!Mover) return;
	if (!IsActorActivator(OtherActor)) return;

	OverlapCount--;
	if (OverlapCount > 0) return;
	Trigger(false);
}

void UTriggerComponent::Trigger(bool bTrigger) const
{
	if (!Mover) return;
	if (bTrigger)
	{
		Mover->Open();
	}
	else
	{
		Mover->Close();
	}
}
