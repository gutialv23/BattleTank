// Copyright (C) - Alvaro Garcia Gutierrez

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

// Forward declarations
class UTankAimingComponent;

/**
 * Responsible for helping the AI tanks aim.
 */

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
    GENERATED_BODY()
        
public:
    // Called when the game starts
    virtual void BeginPlay () override ;

    // Called every frame
    virtual void Tick ( float DeltaTime ) override ;

protected:
    // How close can the AI Tank get
    UPROPERTY( EditDefaultsOnly , Category = "Setup" )
    float AcceptanceRadius = 80000.f ;

};
