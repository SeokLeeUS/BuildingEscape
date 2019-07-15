// Copyright Seok Lee 2019

#include "PositionReporter1.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UPositionReporter1::UPositionReporter1()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPositionReporter1::BeginPlay()
{
	Super::BeginPlay();
	FString ObjectName = GetOwner()->GetName();
	FString ObjectPos = GetOwner()->GetTransform().GetLocation().ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s is at %s"), *ObjectName, *ObjectPos);
	// ...
	
}


// Called every frame
void UPositionReporter1::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

