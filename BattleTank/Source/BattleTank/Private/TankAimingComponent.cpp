// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel *BarrelToSet)
{
	Barrel = BarrelToSet;
}


void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }

	FVector OutLaunchVelocity;

	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(this,
													OutLaunchVelocity,
													Barrel->GetSocketLocation(FName("Projectile")),
													HitLocation,
													LaunchSpeed,
													ESuggestProjVelocityTraceOption::DoNotTrace);

	if (bHaveAimSolution)
	{
		FVector AimDirection = OutLaunchVelocity.GetSafeNormal();

		MoveBarrelTowards(AimDirection);
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{

	// Get Barrel current angle (vector)
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator AimRotator = AimDirection.Rotation();
	BarrelRotator.Pitch = AimRotator.Pitch;

	Barrel->Elevate(5.f); //TODO remove magic number

	// Barrel->SetWorldRotation(BarrelRotator);

	// Calculate de difference between this and the Aim Direction (Pitch)
	// Rotate the Barrel to aim at that direction

	//	UE_LOG(LogTemp, Warning, TEXT("%s firing with this Rotation %s to this direcction %s"), *GetOwner()->GetName(), *BarrelRotator.ToString(), *AimDirection.ToString())

}
