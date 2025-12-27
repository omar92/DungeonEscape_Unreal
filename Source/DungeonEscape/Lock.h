// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TriggerComponent.h"
#include "GameFramework/Actor.h"
#include "Lock.generated.h"

UCLASS()
class DUNGEONESCAPE_API ALock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALock();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent * RootComp;
	
	UPROPERTY(VisibleAnywhere)
	UTriggerComponent * TriggerComponent;
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent * KeyItemMeshComponent;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere)
	FString KeyTag = "KeyItem";
	
	UPROPERTY(EditAnywhere)
	bool IsKeyPlaced = false;

	//setter and getter
	void SetIsKeyPlaced(bool bPlaced) ;
	bool GetIsKeyPlaced();
	
};
