// Fill out your copyright notice in the Description page of Project Settings.


#include "GoKart.h"

#include "Components/InputComponent.h"

// Sets default values
AGoKart::AGoKart()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGoKart::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGoKart::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Force = GetActorForwardVector() * MaxDrivingForce * Throttle ;
	FVector Acceleration = Force / Mass;
	Velocity += Acceleration * DeltaTime;

	ApplyRotation(DeltaTime);
	UpdateTranslationWithVelocity(DeltaTime);

}

void AGoKart::ApplyRotation(float DeltaTime)
{
	float RotationAngle = Steering * MaxDegreesPerSecond * DeltaTime;
	FQuat DeltaRotation(GetActorUpVector(), FMath::DegreesToRadians(RotationAngle));

	Velocity = DeltaRotation.RotateVector(Velocity);

	AddActorWorldRotation(DeltaRotation);
}

void AGoKart::UpdateTranslationWithVelocity(float DeltaTime)
{
	FVector Translation = Velocity * 100 * DeltaTime;

	FHitResult HitResult;

	AddActorWorldOffset(Translation, true, &HitResult);

	if (HitResult.IsValidBlockingHit()) {
		Velocity = FVector::ZeroVector;
	}
}

// Called to bind functionality to input
void AGoKart::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AGoKart::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AGoKart::MoveRight);

}

void AGoKart::MoveForward(float Value) {

	Throttle = Value;
}

void AGoKart::MoveRight(float Value)
{
	Steering = Value;
}

