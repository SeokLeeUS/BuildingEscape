// Copyright Seok Lee 2019

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "Open_Door.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpen_Door : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpen_Door();


	UPROPERTY(BlueprintAssignable)
		FDoorEvent OnOpen;

	UPROPERTY(BlueprintAssignable)
		FDoorEvent OnClose;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	void CloseDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


private:
	UPROPERTY(EditAnywhere)
	float OpenAngle = 90.0f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;

	//UPROPERTY(EditAnywhere)
	//AActor* ActorThatOpens;

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 1.f;
	float LastDoorOpenTime;

	AActor* Owner; // owning door

	float GetTotalMassOfActorsOnPlate();
};
