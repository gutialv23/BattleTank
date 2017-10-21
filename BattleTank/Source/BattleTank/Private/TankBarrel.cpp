// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"





void UTankBarrel::Elevate(float DegreesPerSecond)
{
	// Move the barrel the reight amount this frame

	UE_LOG(LogTemp, Warning, TEXT("Barrel elevate called with %f degrees"), DegreesPerSecond)
}