// Copyright (C) - Alvaro Garcia Gutierrez

#pragma once

#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
    GENERATED_BODY()
    
public:	
    // Sets default values for this actor's properties
    AProjectile ();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay () override;

public:	
    // Called every frame
    virtual void Tick (float DeltaTime) override;

    // Fires this Projectile using the ProjectileMovementComponent with the given speed.
    void LaunchProjectile ( float LaunchSpeed ) ;

protected:

    UProjectileMovementComponent* ProjectileMovementComponent = nullptr ;

    UPROPERTY( VisibleAnywhere , Category = "Components" )
    UStaticMeshComponent* CollisionMesh = nullptr ;
    
    UPROPERTY( VisibleAnywhere , Category = "Components" )
    UParticleSystemComponent* LaunchBlast = nullptr ;

};
