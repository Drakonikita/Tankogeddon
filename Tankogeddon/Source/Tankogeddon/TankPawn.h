// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Cannon.h"
#include "MachinePawn.h"
#include "TankController.h"
#include "GameFramework/Pawn.h"
#include "TankPawn.generated.h"

UCLASS()
class TANKOGEDDON_API ATankPawn : public AMachinePawn
{
	GENERATED_BODY()

public:	
	ATankPawn();

	void MoveForward(float Value);

	void TurnRight(float Value);

	//void Fire();

	void AlterFire();

	void AlterFireStop();

	//void SetupCannon(TSubclassOf<ACannon> NewCannonClass);

	void SwitchCannon();

	void AddAmmo(uint8 Ammo);

	virtual void Tick(float DeltaSeconds) override;

	virtual void BeginPlay() override;

	virtual void Fire() override;

	//void Die() override;

	FVector GetTurretPos();

	void TurnTurretTo(FVector TargetPosition);
	
protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TSubclassOf<ACannon> ProjectileCannonClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TSubclassOf<ACannon> TraceCannonClass;
		
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
	class USpringArmComponent * SpringArm;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
	class UCameraComponent * Camera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
	float MoveSpeed = 200.0f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
	float TurnSpeed = 60.0f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
	float TurnInterpolationKey = 0.2f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
	float ForwardInterpolationKey = 0.02f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
	float TurretTurnInterpolationKey = 0.1f;

	UPROPERTY()
	class ATankController* TankController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
	UForceFeedbackEffect* ShootForceEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
	UCameraShakePattern* ShootShakeEffect;


private:
	float ForwardAxisValue = 0.0f;
	float CurrentForwardAxisValue = 0.0f;
	
	float TurnRightAxisValue = 0.0f;	
	float CurrentTurnRightAxisValue = 0.0f;

	
};
