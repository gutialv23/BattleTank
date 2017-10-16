// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ATank *ControlledTank = GetControlledTank();

	if (ControlledTank != nullptr)
		UE_LOG(LogTemp, Warning, TEXT("PlayerController controls this tank: %s"), *ControlledTank->GetName())
	else
		UE_LOG(LogTemp, Error, TEXT("PlayerController does not control any tank"))

}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}