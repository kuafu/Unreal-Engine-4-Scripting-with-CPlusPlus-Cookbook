// Fill out your copyright notice in the Description page of Project Settings.

#include "ScalingUIGameMode.h"
#include "Chapter9.h"
#include "ScalingUIPlayerController.h"
#include "CustomHUD.h"



AScalingUIGameMode::AScalingUIGameMode()
	:AGameMode()
{
	HUDClass = ACustomHUD::StaticClass();
	PlayerControllerClass = AScalingUIPlayerController::StaticClass();
}
