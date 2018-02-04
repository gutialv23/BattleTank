// Copyright (C) - Alvaro Garcia Gutierrez

#include "BattleTank.h"
#include "TankTrack.h"


UTankTrack::UTankTrack ()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::BeginPlay ()
{
    OnComponentHit.AddDynamic( this , &UTankTrack::OnHit ) ;
}

void UTankTrack::TickComponent ( float DeltaTime , enum ELevelTick TickType , FActorComponentTickFunction* ThisTickFunction )
{
    Super::TickComponent( DeltaTime , TickType , ThisTickFunction ) ;
    
    // Calculate the slippage speed (the sideways component of the speed)
    auto SlippageSpeed = FVector::DotProduct( GetComponentVelocity() , GetRightVector() ) ;

    // Work-out the required acceleration this frame to correct
    auto CorrectionAcceleration = - ( SlippageSpeed / DeltaTime ) * GetRightVector() ;

    // Calculate and apply sideways force (F = m a)
    auto TankRoot = dynamic_cast< UStaticMeshComponent* >( GetOwner()->GetRootComponent() ) ;
    auto CorrectionForce = TankRoot->GetMass() * CorrectionAcceleration / 2 ;

    TankRoot->AddForce( CorrectionForce ) ;
}

void UTankTrack::OnHit( UPrimitiveComponent* HitComponent , AActor* OtherActor , UPrimitiveComponent* OtherComponent , FVector NormalImpulse , const FHitResult& Hit )
{
    UE_LOG( LogTemp , Warning , TEXT( "Hitting from C++" ) )
}

void UTankTrack::SetThrottle ( float Throttle ) 
{
    auto ForceApplied  = GetForwardVector() * Throttle * TrackMaxDrivingForce ;
    auto ForceLocation = GetComponentLocation() ; 

    auto TankRoot = dynamic_cast< UPrimitiveComponent* >( GetOwner()->GetRootComponent() ) ;

    TankRoot->AddForceAtLocation( ForceApplied , ForceLocation ) ;
}