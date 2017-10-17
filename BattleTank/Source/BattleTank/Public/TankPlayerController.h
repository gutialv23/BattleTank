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


	ATank *GetControlledTank() const;

private:
	/*	Start the tank moving the barrel so that a shot
		would hit where the crosshair intersects the world  */
	void AimTowardsCrosshair();

	/* Get world location of linetrace through crosshair, true if hits landscape */
	bool GetSightRayHitLocation( FVector &OutHitLocation ) const;

	// Possible distance from where we can shoot
	const int AimDistance = 10000;
	
};
