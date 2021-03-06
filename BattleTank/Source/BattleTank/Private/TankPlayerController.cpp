// Copyright (C) - Alvaro Garcia Gutierrez

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay ()
{
    Super::BeginPlay() ;
}

void ATankPlayerController::Tick ( float DeltaTime )
{
    Super::Tick( DeltaTime ) ;
    
    AimTowardsCrosshair() ;
}

void ATankPlayerController::AimTowardsCrosshair ()
{
    if ( !GetPawn() ) return ;

    auto TankAimingComponent = GetPawn()->FindComponentByClass< UTankAimingComponent >() ;

    if ( !TankAimingComponent ) return ;

    FVector HitLocation ; // Out parameter

    if ( GetSightRayHitLocation( HitLocation ) )
    {
        // Move the turret to the place where we should hit
        TankAimingComponent->AimAt( HitLocation ) ;
    }
}

bool ATankPlayerController::GetSightRayHitLocation ( FVector& OutHitLocation ) const
{
    FHitResult Hit ;

    // Viewport Size
    int32 ViewportSizeX , ViewportSizeY ; 
    GetViewportSize( ViewportSizeX , ViewportSizeY ) ;

    // Crosshair World Location
    FVector CrosshairWorldLocation , CrosshairWorldDirection ;
    DeprojectScreenPositionToWorld( ViewportSizeX * CrosshairXLocation , ViewportSizeY * CrosshairYLocation , CrosshairWorldLocation , CrosshairWorldDirection ) ;

    // LineTracing to find if we hit something
    FCollisionQueryParams QueryParams( FName( TEXT( "" ) ) , false , GetPawn() ) ;
    GetWorld()->LineTraceSingleByChannel( Hit , CrosshairWorldLocation , CrosshairWorldLocation + CrosshairWorldDirection * ShootDistance , ECollisionChannel::ECC_Visibility , QueryParams ) ;

    if ( Hit.GetActor() != nullptr )
    {
        OutHitLocation = Hit.ImpactPoint ;
        return true ;
    }

    return false ;
}
