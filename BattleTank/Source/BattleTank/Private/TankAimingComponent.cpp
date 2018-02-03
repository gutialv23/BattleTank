// Copyright (C) - Alvaro Garcia Gutierrez

#include "BattleTank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent ()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = false;

    // ...
}

void UTankAimingComponent::Initialise ( UTankBarrel* BarrelToSet , UTankTurret* TurretToSet )
{
    Barrel = BarrelToSet ;
    Turret = TurretToSet ;
}

void UTankAimingComponent::AimAt ( const FVector HitLocation , const float LaunchSpeed )
{
    if ( !Barrel || !Turret ) return ;
    
    FVector OutLaunchVelocity ;

    bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity( this ,
                                                    OutLaunchVelocity ,
                                                    Barrel->GetSocketLocation( FName( "Projectile" ) ) ,
                                                    HitLocation ,
                                                    LaunchSpeed ,
                                                    false , 0 , 0 , 
                                                    ESuggestProjVelocityTraceOption::DoNotTrace ) ;

    if ( bHaveAimSolution )
    {
        FVector AimDirection = OutLaunchVelocity.GetSafeNormal() ;

        MoveBarrelTowards( AimDirection ) ;
    }
}

void UTankAimingComponent::MoveBarrelTowards ( FVector AimDirection )
{
    if ( !Barrel || !Turret ) return ;

    FRotator BarrelRotator = Barrel->GetForwardVector().Rotation() ;
    FRotator AimAsRotator = AimDirection.Rotation() ;
    FRotator DeltaRotator = AimAsRotator - BarrelRotator ;

    Barrel->Elevate( DeltaRotator.Pitch ) ;
    Turret->Rotate ( DeltaRotator.Yaw   ) ;
}
