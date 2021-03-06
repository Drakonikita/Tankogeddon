// Fill out your copyright notice in the Description page of Project Settings.


#include "TankController.h"

#include "TankPawn.h"

ATankController::ATankController()
{
	bShowMouseCursor = true;
}

void ATankController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &ATankController::MoveForward);
	InputComponent->BindAxis("TurnRight", this,  &ATankController::TurnRight);
	InputComponent->BindAction("PrimaryFire", EInputEvent::IE_Pressed, this, &ATankController::Fire);
	InputComponent->BindAction("AlternateFire", EInputEvent::IE_Pressed, this, &ATankController::AlterFire);
	InputComponent->BindAction("AlternateFire", EInputEvent::IE_Released, this, &ATankController::AlterFireStop);
	InputComponent->BindAction("SwitchCannon", EInputEvent::IE_Pressed, this, &ATankController::SwitchCannon);
}

FVector ATankController::GetMousePosition()
{
		return MousePos;	
}

void ATankController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	FVector MouseDirection;
	DeprojectMousePositionToWorld(MousePos, MouseDirection);
	FVector TankPos = TankPawn->GetActorLocation();
	MousePos.Z = TankPos.Z;
	

	FVector Direction = MousePos - TankPos;
	Direction.Normalize();
	MousePos = TankPos + Direction * 1500.0f;

	
	//DrawDebugLine(GetWorld(), TankPawn->GetTurretPos(), MousePos, FColor::Cyan, false, 0.2f, 0, 5);
}


void ATankController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);

	TankPawn = Cast<ATankPawn>(InPawn);
}

void ATankController::MoveForward(float Value)
{
	if(TankPawn)
	{
		TankPawn->MoveForward(Value);
	}
}

void ATankController::TurnRight(float Value)
{
	if(TankPawn)
	{
		TankPawn->TurnRight(Value);
	}
}

void ATankController::Fire()
{
	if(TankPawn)
	{
		TankPawn->Fire();
	}
}

void ATankController::AlterFire()
{
	if(TankPawn)
	{
		TankPawn->AlterFire();
	}
}

void ATankController::AlterFireStop()
{
	if(TankPawn)
	{
		TankPawn->AlterFireStop();
	}
}

void ATankController::SwitchCannon()
{
	if(TankPawn)
	{
		TankPawn->SwitchCannon();
	}
}

