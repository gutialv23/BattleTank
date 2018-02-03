// Copyright (C) - Alvaro Garcia Gutierrez

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
    GENERATED_BODY()
    
public:
    /* RelativeSpeed: +1 indicates max upward speed, -1 indicates max downward speed */
    void Elevate ( float RelativeSpeed ) ;

private:
    UPROPERTY( EditDefaultsOnly , Category = "Setup" )
    float MaxDegreesPerSecond = 20.f ;

    UPROPERTY( EditDefaultsOnly , Category = "Setup" )
    float MaxElevationDegrees = 40.f ;

    UPROPERTY( EditDefaultsOnly , Category = "Setup" )
    float MinElevationDegrees = 0.f ;
    
    
};
