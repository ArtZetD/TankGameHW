// Fill out your copyright notice in the Description page of Project Settings.


#include "TanlPawn.h"

#include "DrawDebugHelpers.h"
#include "Player_Controller.h"
#include "Kismet/KismetMathLibrary.h"

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
	Arm->SetRelativeRotation (FRotator(-90,0,0));
	Arm->bInheritPitch = false;
	Arm->bInheritRoll = false;
	Arm->bInheritYaw= false;
	Arm->TargetArmLength = 2500;
	
}

void ATanlPawn::Forward(float Value)
{
	ForwardScale = Value;
}

void ATanlPawn::Rotate(float Value)
{
	RotationScale = Value;
}

void ATanlPawn::Move()
{
	auto Current_location = GetActorLocation();
	auto FW = GetActorForwardVector() * ((ForwardScale < 0) ? ForwardScale*0.587f : ForwardScale);
	SetActorLocation(Current_location + FW * MovementSpeed * GetWorld()->DeltaTimeSeconds);

}

void ATanlPawn::RotateTank()
{
	auto Current_Rotation = GetActorRotation();
	Current_Rotation.Yaw += RotationScale * RotationSpeed * GetWorld()->DeltaTimeSeconds * ((ForwardScale >= 0) ? 1  : -1);
	SetActorRotation(Current_Rotation);
}

void ATanlPawn::RotateTower()
{
	//if (!PlayerController)
	//	return;
	FVector const Mouse_Pos = PlayerController->GetMousePosition();
	FRotator TargetRotation = UKismetMathLibrary::FindLookAtRotation(Tank_Tower->GetComponentLocation(), Mouse_Pos);
	FRotator const Current_Rotation = Tank_Tower->GetComponentRotation();
	TargetRotation.Pitch = Current_Rotation.Pitch;
	TargetRotation.Roll = Current_Rotation.Roll;
	Tank_Tower->SetWorldRotation(FMath::Lerp(Current_Rotation, TargetRotation, Acceleration));
DrawDebugSphere(GetWorld(),Mouse_Pos, 60,50,  FColor::Red);
	
}

// Called when the game starts or when spawned
void ATanlPawn::BeginPlay()
{
	Super::BeginPlay();
	PlayerController = Cast<APlayer_Controller>(GetController());
}

// Called every frame
void ATanlPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move();
	RotateTank();
	RotateTower();

}

// Called to bind functionality to input
void ATanlPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

