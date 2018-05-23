// Copyright 2018 Benoit Carde box@nantes-interactive.fr 

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;



private:
	// how far ahead of the player can reach in cm
	float Reach = 100.f;
	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UInputComponent* InputComponent = nullptr;
	
	// start RAY CAST and grab
	void Grab();

	// called when grab is released
	void Release();

	void FindPhysicsHandleComponent();

	void SetupInputComponent();

	// return hit for first physics body in reach
	const FHitResult GetFirstPhysicsBodyInReach();

	// returns current en of reach line
	FVector GetReachLineStart();

	// returns current en of reach line
	FVector GetReachLineEnd();
};
