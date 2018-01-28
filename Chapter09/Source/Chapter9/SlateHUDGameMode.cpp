// Fill out your copyright notice in the Description page of Project Settings.

#include "SlateHUDGameMode.h"
#include "Chapter9.h"
#include "CustomHudPlayerController.h"




ASlateHUDGameMode::ASlateHUDGameMode()
	:Super()
{
	PlayerControllerClass = ACustomHUDPlayerController::StaticClass();
}
