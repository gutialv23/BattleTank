// Copyright (C) - Alvaro Garcia Gutierrez

#include "BattleTank.h"
#include "TankTrack.h"


UTankTrack::UTankTrack ()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = false;
}

void UTankTrack::BeginPlay ()
{
    OnComponentHit.AddDynamic( this , &UTankTrack::OnHit ) ;
}

void UTankTrack::OnHit( UPrimitiveComponent* HitComponent , AActor* OtherActor , UPrimitiveComponent* OtherComponent , FVector NormalImpulse , const FHitResult& Hit )
{
    DriveTrack() ;
    ApplySidewaysForce() ;
    CurrentThrottle = 0.f ;
}

void UTankTrack::DriveTrack ()
{
    auto ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce ;
    auto ForceLocation = GetComponentLocation() ;

    auto TankRoot = dynamic_cast< UPrimitiveComponent* >( GetOwner()->GetRootComponent() ) ;

    TankRoot->AddForceAtLocation( ForceApplied , ForceLocation ) ;
}

void UTankTrack::ApplySidewaysForce ()
{
    // Calculate the slippage speed (the sideways component of the speed)
    auto SlippageSpeed = FVector::DotProduct( GetComponentVelocity() , GetRightVector() ) ;

    // Work-out the required acceleration this frame to correct
    auto DeltaTime = GetWorld()->GetDeltaSeconds() ;
    auto CorrectionAcceleration = -( SlippageSpeed / DeltaTime ) * GetRightVector() ;

    // Calculate and apply sideways force (F = m a)
    auto TankRoot = dynamic_cast< UStaticMeshComponent* >( GetOwner()->GetRootComponent() ) ;
    auto CorrectionForce = TankRoot->GetMass() * CorrectionAcceleration / 2 ;

    TankRoot->AddForce( CorrectionForce ) ;
}

void UTankTrack::SetThrottle ( float Throttle ) 
{
    CurrentThrottle = FMath::Clamp< float >( CurrentThrottle + Throttle , -1 , +1 ) ;
}
