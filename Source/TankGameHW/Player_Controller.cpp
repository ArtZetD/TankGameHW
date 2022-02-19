// Fill out your copyright notice in the Description page of Project Settings.


#include "Player_Controller.h"

void APlayer_Controller::SetupInputComponent()
{
	Super::SetupInputComponent();
	 InputComponent->BindAxis("ForwardAxis", this, &APlayer_Controller::OnMoveForward);
	InputComponent->BindAxis("RightAxis", this, &APlayer_Controller::OnMoveRight);
	
}

void APlayer_Controller::BeginPlay()
{
	Super::BeginPlay();
	PTankPawn = Cast<ATanlPawn>(GetPawn());
}

void APlayer_Controller::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void APlayer_Controller::OnMoveForward(float Value)
{
	PTankPawn->Forward(Value);
}

void APlayer_Controller::OnMoveRight(float Value)
{
	PTankPawn->Right(Value);
}
