// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"





void UTankTurret::Rotate ( float RelativeSpeed ) 
{
	// Move the turrent the right amount this frame

	RelativeSpeed = FMath::Clamp< float >( RelativeSpeed , -1.f , 1.f ) ;

	float RotationChange = ( RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds ) ;

	float NewRotation = RelativeRotation.Yaw + RotationChange ;

	SetRelativeRotation( FRotator( 0.f , NewRotation , 0.f ) ) ;

}