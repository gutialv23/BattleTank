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

		
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay () override ;

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent ( class UInputComponent* PlayerInputComponent ) override ;

public:
	// Sets default values for this pawn's properties
	ATank () ;

	UFUNCTION( BlueprintCallable )
	void SetBarrelReference ( UTankBarrel *BarrelToSet ) ;
	
	UFUNCTION( BlueprintCallable )
	void SetTurretReference ( UTankTurret *TurretToSet ) ;
	
	UFUNCTION( BlueprintCallable )
	void Fire () const ;
	
	void AimAt ( FVector Location ) const ;

protected:

	UTankAimingComponent *TankAimingComponent = nullptr ;

private:

	UPROPERTY( EditAnywhere , Category = Firing )
	float LaunchSpeed = 4000.f ;
};
