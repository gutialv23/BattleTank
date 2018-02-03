// Copyright (C) - Alvaro Garcia Gutierrez

#include "BattleTank.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"



void UTankMovementComponent::Initialise ( UTankTrack* LeftTrackToSet , UTankTrack* RightTrackToSet )
{
    LeftTrack  = LeftTrackToSet  ;
    RightTrack = RightTrackToSet ;
}


void UTankMovementComponent::IntendMoveForward ( float Throw )
{
    if ( !LeftTrack || !RightTrack ) { return ; }

    LeftTrack ->SetThrottle( Throw ) ;
    RightTrack->SetThrottle( Throw ) ;
}

void UTankMovementComponent::IntendMoveClockwise ( float Throw )
{
    if ( !LeftTrack || !RightTrack ) { return ; }

    LeftTrack ->SetThrottle(  Throw ) ; 
    RightTrack->SetThrottle( -Throw ) ;
}

void UTankMovementComponent::RequestDirectMove ( const FVector& MoveVelocity , bool bForceMaxSpeed )
{
    // No need to call Super as we're replacing the functionality

    auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal() ;
    auto AIForwardIntention = MoveVelocity.GetSafeNormal() ;

    auto ForwardThrow   = FVector::  DotProduct( TankForward , AIForwardIntention )   ;
    auto ClockwiseThrow = FVector::CrossProduct( TankForward , AIForwardIntention ).Z ;

    IntendMoveForward  (   ForwardThrow ) ;
    IntendMoveClockwise( ClockwiseThrow ) ;
}
