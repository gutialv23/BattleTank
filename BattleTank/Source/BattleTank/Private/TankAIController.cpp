// Copyright (C) - Alvaro Garcia Gutierrez

#include "BattleTank.h"
#include "Tank.h"
#include "TankPlayerController.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay ()
{
    Super::BeginPlay() ;
}

void ATankAIController::Tick ( float DeltaTime )
{
    Super::Tick( DeltaTime ) ;

    auto ControlledTank = Cast<ATank>( GetPawn() ) ;
    auto     PlayerTank = Cast<ATank>( GetWorld()->GetFirstPlayerController()->GetPawn() ) ;

    if( PlayerTank )
    {
        // Move towards the player
        MoveToActor( PlayerTank , AcceptanceRadius ) ; // TODO check AcceptaceRadius is in centimeters

        // Aim towards the player
        ControlledTank->AimAt( PlayerTank->GetActorLocation() ) ;

        // TODO don't fire every frame (limit firing rate)
        ControlledTank->Fire() ; 
    }
}
