// Copyright (C) - Alvaro Garcia Gutierrez

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
    GENERATED_BODY()
    
public:
    /* RelativeSpeed: +1 indicates max upward speed, -1 indicates max downward speed */
    void Rotate ( float RelativeSpeed ) ;

private:
    UPROPERTY( EditAnywhere , Category = "Setup" )
    float MaxDegreesPerSecond = 20.f ;
    
};
