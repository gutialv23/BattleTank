// Fill out your copyright notice in the Description page of Project Settings.

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

    // TODO prevent double-speed due to dual control use
    
}

void UTankMovementComponent::IntendMoveClockwise ( float Throw )
{
    if ( !LeftTrack || !RightTrack ) { return ; }

    LeftTrack ->SetThrottle(  Throw ) ; 
    RightTrack->SetThrottle( -Throw ) ;
    
    // TODO prevent double-speed due to dual control use
    
}

void UTankMovementComponent::RequestDirectMove ( const FVector& MoveVelocity , bool bForceMaxSpeed )
{
    // No need to call Super as we're replacing the functionality

    auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal() ;
    auto AIForwardIntention = MoveVelocity.GetSafeNormal() ;

    auto Throw = FVector::DotProduct( TankForward , AIForwardIntention ) ;

    IntendMoveForward( Throw ) ;

    UE_LOG( LogTemp , Warning , TEXT("%s vectoring to %s") , *GetOwner()->GetName() , *MoveVelocity.GetSafeNormal().ToString() )
}
