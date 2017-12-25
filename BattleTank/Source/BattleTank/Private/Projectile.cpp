// Fill out your copyright notice in the Description page of Project Settings.

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
    if ( !ProjectileMovementComponent ) return ;

    UE_LOG( LogTemp , Warning , TEXT( "%f: Firing projectile %s" ) , GetWorld()->GetTimeSeconds() , *GetName() )

    ProjectileMovementComponent->SetVelocityInLocalSpace( FVector::ForwardVector * LaunchSpeed ) ;
    ProjectileMovementComponent->Activate() ;
}
