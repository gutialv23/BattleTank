// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"


void UTankTrack::SetThrottle ( float Throttle ) 
{
    //GetWorld()->GetTimeSeconds()
    UE_LOG( LogTemp , Warning , TEXT( "%s Throttle: %f" ) , *GetName() , Throttle )

    // TODO clamp actual throttle value so player can't over-drive

    auto ForceApplied  = GetForwardVector() * Throttle * TrackMaxDrivingForce ;
    auto ForceLocation = GetComponentLocation() ; 

    auto TankRoot = dynamic_cast< UPrimitiveComponent* >( GetOwner()->GetRootComponent() ) ;

    TankRoot->AddForceAtLocation( ForceApplied , ForceLocation ) ;
}