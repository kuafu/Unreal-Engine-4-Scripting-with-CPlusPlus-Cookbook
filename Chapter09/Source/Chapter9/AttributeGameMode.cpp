// Fill out your copyright notice in the Description page of Project Settings.

#include "AttributeGameMode.h"
#include "Chapter9.h"




FText AAttributeGameMode::GetButtonLabel() const
{
	FVector ActorLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	return FText::FromString(FString::Printf(TEXT("-%f, %f, %f"), ActorLocation.X, ActorLocation.Y, ActorLocation.Z));
}

void AAttributeGameMode::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;

	Widget = SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Bottom)
		[
			SNew(STextBlock)
			.Text(TAttribute<FText>::Create(TAttribute<FText>::FGetter::CreateUObject(this,
				&AAttributeGameMode::GetButtonLabel)))
		];

	GEngine->GameViewport->AddViewportWidgetForPlayer(GetWorld()->GetFirstLocalPlayerFromController(),
		Widget.ToSharedRef(), 1);
}
