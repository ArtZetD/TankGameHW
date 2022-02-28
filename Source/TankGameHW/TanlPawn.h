// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "TanlPawn.generated.h"
class APlayer_Controller;
UCLASS()
class TANKGAMEHW_API ATanlPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATanlPawn();
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Collision")
	UBoxComponent* Collision;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Meshes")
	UStaticMeshComponent* Tank_Body;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Meshes")
	UStaticMeshComponent* Tank_Tower;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Camera")
	UCameraComponent* Camera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Camera")
	USpringArmComponent* Arm;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tank Parametres")
	float MovementSpeed = 1500;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tank Parametres")
	float RotationSpeed = 40;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tank Parametres")
	float Acceleration = .5;


	void Forward (float Value);
	void Rotate (float Value);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	float ForwardScale;
	float RotationScale;
	

	void Move();
	void RotateTank();
	void RotateTower();

	


public:
	UPROPERTY()
	APlayer_Controller* PlayerController;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

