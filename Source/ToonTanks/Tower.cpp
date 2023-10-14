// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"

void ATower::Tick(float DeltaTime){
    Super::Tick(DeltaTime);
    /*Find the DIstance to the tank

    check to see if the tank is in range
    
    if in range, rotate turret toward tank*/

    if(Tank)
    {
        float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
        if(Distance<=FireRange){
            RotateTurret(Tank->GetActorLocation());
        }
    }
}

void ATower::BeginPlay(){
    Super::BeginPlay();

    Tank =Cast<ATank>(UGame playStatics :: GetPlayerPawn(this,0));
}