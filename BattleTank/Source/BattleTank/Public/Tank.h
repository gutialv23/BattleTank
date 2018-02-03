// Copyright (C) - Alvaro Garcia Gutierrez

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// Forward declarations
class UTankAimingComponent   ;
class UTankBarrel ;
class AProjectile ;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
    GENERATED_BODY()

        
protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay () override ;

public:
    // Sets default values for this pawn's properties
    ATank () ;

    UFUNCTION( BlueprintCallable )
    void Fire () ;
    
    void AimAt ( const FVector Location ) const ;

protected:
    
    UPROPERTY( BlueprintReadOnly )
    UTankAimingComponent* TankAimingComponent = nullptr ;

private:

    UPROPERTY( EditDefaultsOnly , Category = "Setup" )
    TSubclassOf< AProjectile > ProjectileBlueprint ;

    UPROPERTY( EditDefaultsOnly , Category = "Firing" )
    float LaunchSpeed = 4000.f ;
    
    UPROPERTY( EditDefaultsOnly , Category = "Firing" )
    float ReloadTimeInSeconds = 3.f ;

    // Local reference to the barrel to spawn projectiles
    UTankBarrel* Barrel = nullptr ;                         // TODO remove

    float LastFireTime = 0.f ; 
};
