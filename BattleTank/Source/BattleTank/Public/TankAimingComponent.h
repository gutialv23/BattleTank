// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	
public:	
	void SetBarrelReference(UStaticMeshComponent *BarrelToSet);

	// TODO void SetTurretReference(UStaticMeshComponent *BarrelToSet);

	void AimAt(FVector Location, float LaunchSpeed);

private:
	void MoveBarrelTowards(FVector AimDirection);

private:
	UStaticMeshComponent *Barrel = nullptr;
	// TODO UStaticMeshComponent *Turret = nullptr;

	
};
