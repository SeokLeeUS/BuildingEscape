// Copyright Seok Lee 2019

#include "Open_Door.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#define OUT

// Sets default values for this component's properties
UOpen_Door::UOpen_Door()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpen_Door::BeginPlay()
{
	Super::BeginPlay();

	//ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	Owner = GetOwner();
	//OpenDoor();

	
}

void UOpen_Door::OpenDoor()
{
	//AActor * Owner = GetOwner();
	//float Owner = GetOwner()->GetActorRotation().Yaw;
	
	//Owner->SetActorRotation(FRotator(0.f, OpenAngle, 0.f));
	OnOpen.Broadcast();
}

void UOpen_Door::CloseDoor()
{
	//AActor * Owner = GetOwner();
	//float Owner = GetOwner()->GetActorRotation().Yaw;
	//Owner->SetActorRotation(FRotator(0.f, 0.f, 0.f));
	OnClose.Broadcast();
}



// Called every frame
void UOpen_Door::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// poll the trigger volume
	if (GetTotalMassOfActorsOnPlate() > 30.f) //TODO make into a parameter
	{
		//OpenDoor();
		//LastDoorOpenTime = GetWorld()->GetTimeSeconds();
		OnOpen.Broadcast();
	}

	else
	{
		OnClose.Broadcast();
	}
}

float UOpen_Door::GetTotalMassOfActorsOnPlate()
{
	float TotalMass = 0.f;

	// find all the overlapping actors
	TArray<AActor*> OverlappingActors;
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);
	// interate through them adding their masses
	for (auto& Actor : OverlappingActors)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("%s on pressure plate"), *Actor->GetName())
	}



	return TotalMass;
}