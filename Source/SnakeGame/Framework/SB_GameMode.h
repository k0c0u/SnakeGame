// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SnakeGame/Core/Game.h"
#include "GameFramework/GameModeBase.h"
#include "SB_GameMode.generated.h"

class ASG_Grid;

UCLASS()
class SNAKEGAME_API ASB_GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void StartPlay() override;


protected:
	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	bool bOverrideUserSettings{false};
	
	UPROPERTY(EditDefaultsOnly, meta = (ClampMin = "10", ClampMax = "100", EditCondition = "bOverrideUserSettings", EditConditionHides), Category = "Settings")
	FUintPoint GridSize{10, 10};

	UPROPERTY(EditDefaultsOnly, meta = (ClampMin = "10", ClampMax = "100", EditCondition = "bOverrideUserSettings", EditConditionHides), Category = "Settings")
	uint32 CellSize{10};

	UPROPERTY(EditDefaultsOnly, meta = (ClampMin = "4", ClampMax = "10", EditCondition = "bOverrideUserSettings", EditConditionHides), Category = "Settings")
	uint32 SnakeDefaultSize{5};

	UPROPERTY(EditDefaultsOnly, meta = (ClampMin = "0.01", ClampMax = "10", EditCondition = "bOverrideUserSettings", EditConditionHides), Category = "Settings")
	float GameSpeed{1.0f};

	UPROPERTY(EditDefaultsOnly, Category = "Design")
	TSubclassOf<ASG_Grid> GridVisualClass;
	/*
	UPROPERTY(EditDefaultsOnly, Category = "Design")
	TSubclassOf<ASG_Snake> SnakeVisualClass;

	UPROPERTY(EditDefaultsOnly, Category = "Design")
	TSubclassOf<ASG_Food> FoodVisualClass;

	UPROPERTY(EditDefaultsOnly, Category = "Design")
	TObjectPtr<UDataTable> ColorsTable;

	UPROPERTY(EditDefaultsOnly, Category = "SnakeInput")
	TObjectPtr<UInputAction> MoveForwardInputAction;

	UPROPERTY(EditDefaultsOnly, Category = "SnakeInput")
	TObjectPtr<UInputAction> MoveRightInputAction;

	UPROPERTY(EditDefaultsOnly, Category = "SnakeInput")
	TObjectPtr<UInputAction> ResetGameInputAction;

	UPROPERTY(EditDefaultsOnly, Category = "SnakeInput")
	TObjectPtr<UInputMappingContext> InputMapping;*/
	
private:
	TUniquePtr<Snake::Game> Game;

	UPROPERTY()
	TObjectPtr<ASG_Grid> GridVisual;
	
};
