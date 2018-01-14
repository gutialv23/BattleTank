// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Forward declarations
class UTankBarrel ;
class UTankTurret ;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
    GENERATED_BODY()

public:	
    // Sets default values for this component's properties
    UTankAimingComponent () ;
    
public:	
    void SetBarrelReference ( UTankBarrel *BarrelToSet ) ;
    void SetTurretReference ( UTankTurret *TurretToSet ) ;

    void AimAt ( const FVector Location , const float LaunchSpeed ) ;

private:
    void MoveBarrelTowards ( FVector AimDirection ) ;

private:
    UTankBarrel *Barrel = nullptr ;
    UTankTurret *Turret = nullptr ;

    
};
