// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TanlPawn.h"
#include "GameFramework/PlayerController.h"
#include "Player_Controller.generated.h"

/**
 *
 * help
 */
UCLASS()
class TANKGAMEHW_API APlayer_Controller : public APlayerController
{
	GENERATED_BODY()
	
	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	
	

	void OnMoveForward(float Value);
	void OnRotateRight(float Value);

	UPROPERTY()
	ATanlPawn* PTankPawn;



	FVector Mouse_World_Pos;
public:
	FVector GetMousePosition()
	{
		return Mouse_World_Pos;
	};
};
