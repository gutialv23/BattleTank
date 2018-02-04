// Copyright (C) - Alvaro Garcia Gutierrez

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay ()
{
    Super::BeginPlay() ;
}

void ATankAIController::Tick ( float DeltaTime )
{
    Super::Tick( DeltaTime ) ;

    auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn() ;
    
    auto TankAimingComponent = GetPawn()->FindComponentByClass< UTankAimingComponent >() ;

    if( PlayerTank && TankAimingComponent )
    {
        // Move towards the player
        MoveToActor( PlayerTank , AcceptanceRadius ) ; // TODO check AcceptaceRadius is in centimeters

        // Aim towards the player
        TankAimingComponent->AimAt( PlayerTank->GetActorLocation() ) ;

        // TODO don't fire every frame (limit firing rate)
        if ( TankAimingComponent->GetFiringStatus() == EFiringStatus::Locked )
        {
            TankAimingComponent->Fire() ; 
        }
    }
}
