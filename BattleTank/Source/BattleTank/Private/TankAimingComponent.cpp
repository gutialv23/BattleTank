// Copyright (C) - Alvaro Garcia Gutierrez

#include "BattleTank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent ()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = true;
}

void UTankAimingComponent::BeginPlay ()
{
    LastFireTime = GetWorld()->GetTimeSeconds() ;
}

void UTankAimingComponent::TickComponent ( float DeltaTime , enum ELevelTick TickType , FActorComponentTickFunction* ThisTickFunction )
{
    bool isReloaded = ( GetWorld()->GetTimeSeconds() - LastFireTime ) > ReloadTimeInSeconds ;

         if ( Ammo <= 0        ) FiringStatus = EFiringStatus::OutOfAmmo ;
    else if ( !isReloaded      ) FiringStatus = EFiringStatus::Reloading ;
    else if ( IsBarrelMoving() ) FiringStatus = EFiringStatus::Aiming    ;
    else                         FiringStatus = EFiringStatus::Locked    ;
}

void UTankAimingComponent::Initialise ( UTankBarrel* BarrelToSet , UTankTurret* TurretToSet )
{
    Barrel = BarrelToSet ;
    Turret = TurretToSet ;
}

EFiringStatus UTankAimingComponent::GetFiringStatus() const
{
    return FiringStatus ;
}

void UTankAimingComponent::AimAt ( const FVector HitLocation )
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
        AimDirection = OutLaunchVelocity.GetSafeNormal() ;

        MoveBarrelTowards( AimDirection ) ;
    }
}

void UTankAimingComponent::Fire ()
{
    if ( !Barrel || !ProjectileBlueprint ) return ;

    if ( FiringStatus == EFiringStatus::Aiming || FiringStatus == EFiringStatus::Locked )
    {
        auto Projectile = GetWorld()->SpawnActor< AProjectile >( ProjectileBlueprint 
                                                               , Barrel->GetSocketLocation( FName( "Projectile" ) ) 
                                                               , Barrel->GetSocketRotation( FName( "Projectile" ) ) ) ;

        Projectile->LaunchProjectile( LaunchSpeed ) ;
        LastFireTime = GetWorld()->GetTimeSeconds() ;

        Ammo -- ;
    }
}

void UTankAimingComponent::MoveBarrelTowards ( FVector AimDir )
{
    if ( !Barrel || !Turret ) return ;

    FRotator BarrelRotator = Barrel->GetForwardVector().Rotation() ;
    FRotator AimAsRotator = AimDir.Rotation() ;
    FRotator DeltaRotator = AimAsRotator - BarrelRotator ;

    Barrel->Elevate( DeltaRotator.Pitch ) ;

    if ( FMath::Abs( DeltaRotator.Yaw ) > 180.f ) Turret->Rotate( - DeltaRotator.Yaw ) ;
    else                                          Turret->Rotate(   DeltaRotator.Yaw ) ;
}

bool UTankAimingComponent::IsBarrelMoving () const 
{
    if ( !Barrel ) return false ;

    return !AimDirection.Equals( Barrel->GetForwardVector() , 0.01f ) ;
}
