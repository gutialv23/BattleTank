// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent ()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::SetBarrelReference ( UTankBarrel *BarrelToSet )
{
	Barrel = BarrelToSet ;
}


void UTankAimingComponent::AimAt ( FVector HitLocation , float LaunchSpeed )
{
	if ( !Barrel ) { return; }

	FVector OutLaunchVelocity;

	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity( this ,
													OutLaunchVelocity ,
													Barrel->GetSocketLocation( FName( "Projectile" ) ) ,
													HitLocation ,
													LaunchSpeed ,
													false , 0 , 0 , 
													ESuggestProjVelocityTraceOption::DoNotTrace ) ;

	if (bHaveAimSolution)
	{
		FVector AimDirection = OutLaunchVelocity.GetSafeNormal() ;

		MoveBarrelTowards( AimDirection ) ;
		UE_LOG( LogTemp , Warning , TEXT( "%f: Solution found" ) , GetWorld()->GetTimeSeconds() )
	}
	else
	{
		UE_LOG( LogTemp , Warning , TEXT( "%f: Solution not found" ) , GetWorld()->GetTimeSeconds() )
	}
}

void UTankAimingComponent::MoveBarrelTowards ( FVector AimDirection )
{
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation() ;
	FRotator AimAsRotator = AimDirection.Rotation() ;
	FRotator DeltaRotator = AimAsRotator - BarrelRotator ;

	Barrel->Elevate( DeltaRotator.Pitch ) ;
}
