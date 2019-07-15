// Copyright Seok Lee 2019

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "Public/DrawDebugHelpers.h"
#include "GameFramework/Actor.h"
#include "Components/ActorComponent.h"
#include "Components/InputComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	FString Location;
	FString Rotation;
	float Reach = 100.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;

	// Ray-cast and grab what's in reach
	void Grab();
	void Release();
	void FindPhysicsHandleComponent();
	void SetupInputComponent();

	// return hit for first physics body in reach 
	FHitResult GetFirstPhysicsBodyInReach() const;

	// return current start of reach line
	FVector GetReachLineStart() const;

	// return current end of reach line
	FVector GetReachLineEnd() const;

};
