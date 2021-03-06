// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GoKart.generated.h"

UCLASS()
class CRAZYKARTS_API AGoKart : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AGoKart();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:

	FVector Velocity;

	void ApplyRotation(float DeltaTime);
	void UpdateTranslationWithVelocity(float DeltaTime);

	// Car Mass in Kg;
	UPROPERTY(EditAnywhere)
	float Mass = 1000;

	// Force Applied to Car In full Throttle in N unit;
	UPROPERTY(EditAnywhere)
	float MaxDrivingForce = 10000;

	//Max Degree To rotate in Sec Deg/Sec
	UPROPERTY(EditAnywhere)
	float MaxDegreesPerSecond = 90;

	void MoveForward(float Value);
	void MoveRight(float Value);

	float Throttle;
	float Steering;

};
