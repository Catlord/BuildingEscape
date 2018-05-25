// Copyright 2018 Benoit Carde box@nantes-interactive.fr 

#pragma once
#include "Engine/TriggerVolume.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	// Called when the game starts
	virtual void BeginPlay() override;

	//void OpenDoor();
	//void CloseDoor();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
	FDoorEvent OnOpen;

	UPROPERTY(BlueprintAssignable)
	FDoorEvent OnClose;

private:
	//UPROPERTY(EditAnywhere) déja dans l'editeur de bp
	//float OpenAngle = -90.f;

	UPROPERTY(EditAnywhere) 
	class ATriggerVolume* PressurePlate = nullptr;

	float TriggerMass = 30.f;
	//UPROPERTY(EditAnywhere)
	//float DoorCloseDelay = 1.f;

	//float LastDoorOpenTime;

	//AActor* ActorThatOpens;
	AActor* Owner = nullptr;

	float GetTotalMassOfActorsOnPLate();
};
