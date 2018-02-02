// Copyright (C) - Alvaro Garcia Gutierrez

#include "BattleTank.h"
#include "Projectile.h"


// Sets default values
AProjectile::AProjectile()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    ProjectileMovementComponent = CreateDefaultSubobject< UProjectileMovementComponent >( FName( "MovementComponent" ) ) ;
    ProjectileMovementComponent->bAutoActivate = false ;    

}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
    Super::BeginPlay();
    
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void AProjectile::LaunchProjectile ( float LaunchSpeed ) 
{
    ProjectileMovementComponent->SetVelocityInLocalSpace( FVector::ForwardVector * LaunchSpeed ) ;
    ProjectileMovementComponent->Activate() ;
}
