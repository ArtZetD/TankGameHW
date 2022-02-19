// Fill out your copyright notice in the Description page of Project Settings.


#include "TanlPawn.h"

// Sets default values
ATanlPawn::ATanlPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	RootComponent = Collision;
	
	Tank_Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tank_Body"));
	Tank_Body->SetupAttachment(RootComponent);
	
	Tank_Tower = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tank_Tower"));
	Tank_Tower->SetupAttachment(Tank_Body);

	Arm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Arm"));
	Arm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(Arm);

	Camera->bUsePawnControlRotation = false;
	Arm->bInheritPitch = false;
	Arm->bInheritRoll = false;
	Arm->bInheritYaw= false;
	Arm->TargetArmLength = 2500;
	
}

void ATanlPawn::Forward(float Value)
{
	ForwardScale = Value;
}

void ATanlPawn::Right(float Value)
{
	RightScale = Value;
}

void ATanlPawn::Move()
{
	auto Current_location = GetActorLocation();
	auto FW = GetActorForwardVector() * ForwardScale;
	auto RW = GetActorRightVector() * RightScale;

	
	auto destination = RW+ FW ;
	destination.Normalize();
	SetActorLocation(Current_location + destination * MovementSpeed * GetWorld()->DeltaTimeSeconds);

}

// Called when the game starts or when spawned
void ATanlPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATanlPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move();

}

// Called to bind functionality to input
void ATanlPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

