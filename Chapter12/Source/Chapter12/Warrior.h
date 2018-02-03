// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Logging.h"
#include "GameFramework/Character.h"
#include "GameplayAbility.h"
#include "AbilitySystemComponent.h"
#include "GameplayAbilitySet.h"
#include "AbilitySystemInterface.h"
#include "GameplayTaskOwnerInterface.h"
#include "GameUnitAttributeSet.h"
#include "Warrior.generated.h"

UCLASS()
class CHAPTER12_API AWarrior : public ACharacter, 
	public IAbilitySystemInterface, public IGameplayTaskOwnerInterface
{
	GENERATED_BODY()
public:
	// Lists key triggers for various abilities for the player.
	// Selects an instance of UGameplayAbilitySet (which is a UDataAsset derivative
	// that you construct in the Content Browser).
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stats)
	UGameplayAbilitySet* gameplayAbilitySet;

	// The AbilitySystemComponent itself
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stats)
	UAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stats)
	UGameplayTasksComponent* GameplayTasksComponent;

	// This is the particleSystem that we create with the
	// GameplayTask_CreateParticles object.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
	UParticleSystem* particleSystem;

	FVector2D lastInput;

	// Sets default values for this actor's properties
	AWarrior(const FObjectInitializer& PCIP);

	// IAbilitySystemInterface implementation:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const { return AbilitySystemComponent; }

	// <GameplayTaskOwnerInterface>
	virtual UGameplayTasksComponent* GetGameplayTasksComponent(const UGameplayTask& Task) const { return GameplayTasksComponent; }
	// This gets called both when task starts and when task gets resumed.
	// Check Task.GetStatus() if you want to differenciate.
	virtual void OnTaskActivated(UGameplayTask& Task) 
	{ 
		Info(FS("Task %s activated", *Task.GetInstanceName().ToString()));
	}

	// This gets called both when task finished and when task gets paused. 
	// Check Task.GetStatus() if you want to differenciate.
	virtual void OnTaskDeactivated(UGameplayTask& Task) { }

	virtual AActor* GetOwnerActor(const UGameplayTask* Task) const 
	{
		return Task->GetOwnerActor();  // This will give us the accurate answer for the Task..
	}
	// </End GameplayTaskOwnerInterface>

	virtual void PostInitializeComponents() override;

	virtual void SetupPlayerInputComponent(UInputComponent* Input)override;

	void Forward(float amount);
	void Back(float amount);
	void Right(float amount);
	void Left(float amount);

	virtual void BeginPlay() override;

	void TestGameplayEffect();
	void RecoverHpEffectEnded();

	virtual void Tick(float DeltaSeconds) override;

};
