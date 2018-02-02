// Copyright (C) - Alvaro Garcia Gutierrez

#include "BattleTank.h"
#include "TankBarrel.h"





void UTankBarrel::Elevate ( float RelativeSpeed )
{
    // Move the barrel the right amount this frame

    RelativeSpeed = FMath::Clamp< float >( RelativeSpeed , -1.f , 1.f ) ;

    float ElevationChange = ( RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds ) ;

    float NewElevation = FMath::Clamp< float >( RelativeRotation.Pitch + ElevationChange , MinElevationDegrees , MaxElevationDegrees ) ;

    SetRelativeRotation( FRotator( NewElevation , 0.f , 0.f ) ) ;
}