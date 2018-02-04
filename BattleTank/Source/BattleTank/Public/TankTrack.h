// Copyright (C) - Alvaro Garcia Gutierrez

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force, and to apply forces to the tank.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
    GENERATED_BODY()

public:
    UTankTrack() ;

private:
    // Called when the game starts
    virtual void BeginPlay () override ;

    UFUNCTION()
    void OnHit( UPrimitiveComponent* HitComponent , AActor* OtherActor , UPrimitiveComponent* OtherComponent , FVector NormalImpulse , const FHitResult& Hit ) ;
    
    void DriveTrack () ;

    void ApplySidewaysForce () ;

public:

    // Sets a throttle between -1 and +1
    UFUNCTION( BlueprintCallable )
    void SetThrottle ( float Throttle ) ;

    // Max force per track (in Newtons)
    UPROPERTY( EditDefaultsOnly , Category = "Setup" )
    float TrackMaxDrivingForce = 400000.f ;         // <- NOTE: Assuming 40 tonne tank and 1g acceleration.

private:

    float CurrentThrottle = 0.f ;

};
