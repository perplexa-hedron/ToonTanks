// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
ATank::ATank()
{
    // PrimaryActorTick.bCanEverTick = true;
    SpringArm = CreateDefaultSubobject<USpringComponent>(TEXT("Spring Component"));
    SpringArm->SetupAttachment(RootComponent);
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA COMPONENT"));
    Camera->SetupAttachment(SpringArm);
}