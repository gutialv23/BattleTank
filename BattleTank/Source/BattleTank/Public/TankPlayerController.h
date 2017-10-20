// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
		
public:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	/*	Returns our controlled Tank if found */
	ATank *GetControlledTank() const;

	/*	Start the tank moving the barrel so that a shot
		would hit where the crosshair intersects the world  */
	void AimTowardsCrosshair();

	/*	Get world location of linetrace through crosshair, true if hits landscape */
	bool GetSightRayHitLocation( FVector &OutHitLocation ) const;
		
public:
	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.33333f;

	/*	Possible distance from where we can shoot */
	UPROPERTY(EditAnywhere)
	float ShootDistance = 100000.f;

};
