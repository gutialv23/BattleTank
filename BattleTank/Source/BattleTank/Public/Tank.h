// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// Forward declarations
class UTankAimingComponent ;
class UTankBarrel ;
class UTankTurret ;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank () ;

	UFUNCTION( BlueprintCallable )
	void SetBarrelReference ( UTankBarrel *BarrelToSet ) ;
	
	UFUNCTION( BlueprintCallable )
	void SetTurretReference ( UTankTurret *TurretToSet ) ;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay () override ;

	UTankAimingComponent *TankAimingComponent = nullptr ;

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent ( class UInputComponent* PlayerInputComponent ) override ;

	void AimAt ( FVector Location ) const ;

private:

	UPROPERTY( EditAnywhere , Category = Firing )
	float LaunchSpeed = 100000.f ;			// TODO find sensible default value
};
