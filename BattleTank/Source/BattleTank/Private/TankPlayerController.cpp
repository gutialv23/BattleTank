// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ATank *ControlledTank = GetControlledTank();

	if (ControlledTank != nullptr)
		UE_LOG(LogTemp, Warning, TEXT("PlayerController controls this tank: %s"), *ControlledTank->GetName())
	else
		UE_LOG(LogTemp, Error, TEXT("PlayerController does not control any tank"))

}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{

	if (GetControlledTank() == nullptr) { return; }

	FVector HitLocation; // Out parameter

	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Aiming to this location: %s"), *HitLocation.ToString());
		// Move the turret to the place where we should hit
	}
}

bool ATankPlayerController::GetSightRayHitLocation( FVector &OutHitLocation) const
{
	FHitResult Hit;

	FVector CameraLocation = PlayerCameraManager->GetCameraLocation();
	FRotator CameraRotation = PlayerCameraManager->GetCameraRotation();

	FCollisionQueryParams QueryParams(FName(TEXT("")), false, GetPawn());

	GetWorld()->LineTraceSingleByChannel(Hit, CameraLocation, CameraLocation + CameraRotation.Vector() * AimDistance, ECollisionChannel::ECC_Camera, QueryParams);

	if (Hit.GetActor() != nullptr)
	{
		OutHitLocation = Hit.ImpactPoint;
		return true;
	}

	return false;
}
