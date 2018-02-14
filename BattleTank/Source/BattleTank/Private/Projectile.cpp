// Copyright (C) - Alvaro Garcia Gutierrez

#include "BattleTank.h"
#include "Projectile.h"


// Sets default values
AProjectile::AProjectile()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    CollisionMesh = CreateDefaultSubobject< UStaticMeshComponent >( FName( "Collision Mesh" ) ) ;
    CollisionMesh->SetNotifyRigidBodyCollision( true  ) ; // Generate simulation events
    CollisionMesh->SetVisibility              ( false ) ; // Only see the particle system

    SetRootComponent( CollisionMesh ) ;

    LaunchBlast = CreateDefaultSubobject< UParticleSystemComponent >( FName( "Launch Blast" ) ) ;
    LaunchBlast->AttachTo( RootComponent ) ;

    ProjectileMovementComponent = CreateDefaultSubobject< UProjectileMovementComponent >( FName( "Movement Component" ) ) ;
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
