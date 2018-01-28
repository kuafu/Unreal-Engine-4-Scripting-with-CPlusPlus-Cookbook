// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomHUDGameMode.h"
#include "Chapter9.h"
#include "CustomHUDPlayerController.h"
#include "CustomHUD.h"



ACustomHUDGameMode::ACustomHUDGameMode()
	:AGameMode()
{
	HUDClass = ACustomHUD::StaticClass();
	PlayerControllerClass = ACustomHUDPlayerController::StaticClass();
}
