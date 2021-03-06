// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "HandControllerBase.h"
#include "AVRPawn.generated.h"

UCLASS()
class LIGHTPAINTER_API AAVRPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAVRPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:

	void RightTriggerPressed() { if (RightPaintBrushHandController) RightPaintBrushHandController->TriggerPressed(); }
	void RightTriggerReleased() { if (RightPaintBrushHandController) RightPaintBrushHandController->TriggerReleased(); }
	void Save();
	void Load();

	// Config
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AHandControllerBase> PaintBrushHandControllerClass;

	// Components
	UPROPERTY(VisibleAnywhere)
	USceneComponent* VRRoot;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

	// Reference
	UPROPERTY()
	AHandControllerBase* RightPaintBrushHandController;

	// State
	FString CurrentSlotName;
	
};
