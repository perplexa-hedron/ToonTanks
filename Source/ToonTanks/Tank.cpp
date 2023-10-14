// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"


ATank::ATank()
{
    // PrimaryActorTick.bCanEverTick = true;
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    SpringArm->SetupAttachment(RootComponent);
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm);
}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis(TEXT("MoveForward"),this,&ATank::Move);

    PlayerInputComponent->BindAxis(TEXT("Turn"),this,&ATank::Turn);
}
void ATank:: BeginPlay(){
    Super::BeginPlay();

    PlayerControllerRef = Cast<APlayerController>(GetController());
}
void ATank::Move(float Value)
{
    // UE_LOG(LogTemp,Warning,TEXT("Value: %f"),Value);
    FVector DeltaLocation(0.f);

    DeltaLocation.X = Value * UGameplayStatics::GetWorldDeltaSeconds(this)* Speed;
    AddActorLocalOffset(DeltaLocation,true);
}

void ATank :: Turn(float Value){
    FRotator DeltaRotation = FRotator::ZeroRotator;
    //Yaw = Value * DeltaTime * TurnRate
    DeltaRotation.Yaw = Value*UGameplayStatics::GetWorldDeltaSeconds(this)* TurnRate;
    AddActorLocalRotation(DeltaRotation,true);
}