// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();


	ATank *ControlledTank = GetControlledTank();

	if (ControlledTank != nullptr)
		UE_LOG(LogTemp, Warning, TEXT("AIController controls this tank: %s"), *ControlledTank->GetName())
	else
		UE_LOG(LogTemp, Error, TEXT("AIController does not control any tank"))

}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}