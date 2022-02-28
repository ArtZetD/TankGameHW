// Fill out your copyright notice in the Description page of Project Settings.


#include "Player_Controller.h"

#include "DrawDebugHelpers.h"

void APlayer_Controller::SetupInputComponent()
{
	Super::SetupInputComponent();
	 InputComponent->BindAxis("ForwardAxis", this, &APlayer_Controller::OnMoveForward);
	InputComponent->BindAxis("RotationAxis", this, &APlayer_Controller::OnRotateRight);
	
}

void APlayer_Controller::BeginPlay()
{
	Super::BeginPlay();
	PTankPawn = Cast<ATanlPawn>(GetPawn());
	this->SetShowMouseCursor(true);
}

void APlayer_Controller::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	FVector Mouse_Position, Mouse_Direction;
	DeprojectMousePositionToWorld(Mouse_Position , Mouse_Direction);

	auto Z = FMath::Abs(PTankPawn->GetActorLocation().Z - Mouse_Position.Z);
	 Mouse_World_Pos = Mouse_Position - Mouse_Direction * Z / Mouse_Direction.Z;
//DrawDebugSphere(GetWorld(), Mouse_Position, 3 , 16, FColor::Red);
	DrawDebugSphere(GetWorld(), Mouse_World_Pos, 3 , 16, FColor::Red);
}


void APlayer_Controller::OnMoveForward(float Value)
{
	PTankPawn->Forward(Value);
}

void APlayer_Controller::OnRotateRight(float Value)
{
	PTankPawn->Rotate(Value);
}

