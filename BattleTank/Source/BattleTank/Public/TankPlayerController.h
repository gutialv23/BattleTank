// Copyright (C) - Alvaro Garcia Gutierrez

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

// Forward declarations
class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
    GENERATED_BODY()
        
public:
    // Called when the game starts
    virtual void BeginPlay() override ;

    // Called every frame
    virtual void Tick(float DeltaTime) override ;


protected:
    
    /*	Returns our controlled Tank if found */
    UFUNCTION( BlueprintCallable , Category = "Setup" )
    ATank *GetControlledTank() const ;

private:

    /*	Start the tank moving the barrel so that a shot
        would hit where the crosshair intersects the world  */
    void AimTowardsCrosshair() ;

    /*	Get world location of linetrace through crosshair, true if hits landscape */
    bool GetSightRayHitLocation( FVector &OutHitLocation ) const ;
        
public:
    UPROPERTY( EditDefaultsOnly )
    float CrosshairXLocation = 0.5f ;

    UPROPERTY( EditDefaultsOnly )
    float CrosshairYLocation = 0.33333f ;

    /*	Possible distance from where we can shoot */
    UPROPERTY( EditDefaultsOnly )
    float ShootDistance = 100000.f ;

};
