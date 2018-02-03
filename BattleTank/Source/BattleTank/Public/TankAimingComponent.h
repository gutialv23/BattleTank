// Copyright (C) - Alvaro Garcia Gutierrez

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Enum for aiming state
UENUM()
enum class EFiringStatus : uint8 { Reloading , Aiming , Locked };

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
    
    UFUNCTION( BlueprintCallable )
    void Initialise ( UTankBarrel* BarrelToSet , UTankTurret* TurretToSet ) ;

    void AimAt ( const FVector Location , const float LaunchSpeed ) ;

protected:
    
    UPROPERTY( BlueprintReadOnly , Category = "State" )
    EFiringStatus FiringStatus = EFiringStatus::Reloading ;

private:
    void MoveBarrelTowards ( FVector AimDirection ) ;

    UTankBarrel *Barrel = nullptr ;
    UTankTurret *Turret = nullptr ;
    
};
