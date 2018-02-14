// Copyright (C) - Alvaro Garcia Gutierrez

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Enum for aiming state
UENUM()
enum class EFiringStatus : uint8 { Reloading , Aiming , Locked , OutOfAmmo };

// Forward declarations
class UTankBarrel ;
class UTankTurret ;
class AProjectile ;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    UTankAimingComponent () ;

protected:
    // Called when the game starts
    virtual void BeginPlay () override ;

    // Called every tick
    virtual void TickComponent ( float DeltaTime , enum ELevelTick TickType , FActorComponentTickFunction* ThisTickFunction ) override ;
    
public:
    UFUNCTION( BlueprintCallable , Category = "Setup" )
    void Initialise ( UTankBarrel* BarrelToSet , UTankTurret* TurretToSet ) ;
    
    EFiringStatus GetFiringStatus () const ;

    void AimAt ( const FVector Location ) ;

    UFUNCTION( BlueprintCallable , Category = "Firing" )
    void Fire () ;

protected:

    UPROPERTY( BlueprintReadOnly , Category = "State" )
    EFiringStatus FiringStatus = EFiringStatus::Reloading ;

    UPROPERTY( EditDefaultsOnly , BlueprintReadOnly , Category = "Firing" )
    int32 Ammo = 3 ;

private:
    void MoveBarrelTowards ( FVector AimDirection ) ;

    bool IsBarrelMoving () const ;

    UTankBarrel *Barrel = nullptr ;
    UTankTurret *Turret = nullptr ;
    
    UPROPERTY( EditDefaultsOnly , Category = "Setup" )
    TSubclassOf< AProjectile > ProjectileBlueprint ;

    UPROPERTY( EditDefaultsOnly , Category = "Firing" )
    float LaunchSpeed = 4000.f ;
    
    UPROPERTY( EditDefaultsOnly , Category = "Firing" )
    float ReloadTimeInSeconds = 3.f ;
    
    FVector AimDirection ;

    float LastFireTime = 0.f ; 

};
