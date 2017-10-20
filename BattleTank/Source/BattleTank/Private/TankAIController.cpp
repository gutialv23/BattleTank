// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"
#include "TankPlayerController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();


	ATank *PlayerTank = GetPlayerTank();

	if (PlayerTank != nullptr)
		UE_LOG(LogTemp, Warning, TEXT("AIController found this Player tank: %s"), *PlayerTank->GetName())
	else
		UE_LOG(LogTemp, Error, TEXT("AIController does not found any Player tank"))

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Move towards the player
	AimAtPlayer();
}

void ATankAIController::AimAtPlayer() const
{
	if (GetControlledTank()) 
	{
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
