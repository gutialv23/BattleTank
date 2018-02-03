// Copyright (C) - Alvaro Garcia Gutierrez

#include "BattleTank.h"
#include "Projectile.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "Tank.h"


// Sets default values
ATank::ATank ()
{
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false ;
}

// Called when the game starts or when spawned
void ATank::BeginPlay ()
{
    Super::BeginPlay() ;
    
    TankAimingComponent = FindComponentByClass< UTankAimingComponent >() ;

    if ( !TankAimingComponent )
    {
        UE_LOG( LogTemp , Error , TEXT( "%s: TankAimingComponent not found!" ) , *GetOwner()->GetName() )
    }
}

void ATank::Fire ()
{
    bool isReloaded = ( GetWorld()->GetTimeSeconds() - LastFireTime ) > ReloadTimeInSeconds ;

    if ( !Barrel || !ProjectileBlueprint || !isReloaded ) return ;

    auto Projectile = GetWorld()->SpawnActor< AProjectile >( ProjectileBlueprint 
                                                           , Barrel->GetSocketLocation( FName( "Projectile" ) ) 
                                                           , Barrel->GetSocketRotation( FName( "Projectile" ) ) ) ;

    Projectile->LaunchProjectile( LaunchSpeed ) ;

    LastFireTime = GetWorld()->GetTimeSeconds() ;
}

void ATank::AimAt ( const FVector Location ) const
{
    if ( !TankAimingComponent ) return ;

    TankAimingComponent->AimAt( Location , LaunchSpeed ) ;
}

