// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "TanlPawn.generated.h"

UCLASS()
class TANKGAMEHW_API ATanlPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATanlPawn();
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Collision")
	UBoxComponent* Collision;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Meshes")
	UStaticMeshComponent* Tank_Body;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Meshes")
	UStaticMeshComponent* Tank_Tower;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera")
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera")
	USpringArmComponent* Arm;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tank Parametres")
	float MovementSpeed = 2500;

	void Forward (float Value);
	void Right (float Value);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	float ForwardScale;
	float RightScale;

	void Move();


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

