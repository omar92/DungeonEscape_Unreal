#include "CollectableItem.h"
#include "Engine/Engine.h"

ACollectableItem::ACollectableItem()
{
	// No default value for ItemName by design.
	PrimaryActorTick.bCanEverTick = false;
	
	//add tag 
	Tags.Add("CollectableItem");
}

void ACollectableItem::BeginPlay()
{
	Super::BeginPlay();
	

}
