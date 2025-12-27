#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollectableItem.generated.h"

UCLASS()
class DUNGEONESCAPE_API ACollectableItem : public AActor
{
	GENERATED_BODY()

public:
	ACollectableItem();

	// Public member variable editable anywhere in the editor. No default value is set.
	UPROPERTY(EditAnywhere)
	FString ItemName;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
