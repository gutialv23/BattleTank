// Fill out your copyright notice in the Description page of Project Settings.

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
        // TODO move towards the player

        // Aim towards the player
        ControlledTank->AimAt( PlayerTank->GetActorLocation() ) ;

        // TODO don't fire every frame (limit firing rate)
        ControlledTank->Fire() ; 
    }
}
