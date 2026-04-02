#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactable.generated.h"

class AActor;

UINTERFACE(MinimalAPI, Blueprintable)
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

class DUNGEONESCAPE_API IInteractable : public IInterface
{
	GENERATED_BODY()

public:
	/** Called when this object is interacted with. Implement in Blueprints or override OnInteract_Implementation in C++. */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void OnInteract(AActor* Interactor);

	/** Optional C++ default implementation */
	virtual void OnInteract_Implementation(AActor* Interactor) {}
};
