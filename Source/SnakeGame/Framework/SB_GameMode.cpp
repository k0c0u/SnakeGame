// Fill out your copyright notice in the Description page of Project Settings.


#include "Framework/SB_GameMode.h"
#include "SnakeGame/Core/Types.h"
#include "World/SG_Grid.h"

void ASB_GameMode::StartPlay()
{
	Super::StartPlay();

	const Snake::Settings GS{GridSize.X, GridSize.Y};
	Game = MakeUnique<Snake::Game>(GS);
	check(Game.IsValid());
	const FTransform GridOrigin = FTransform::Identity;
	check(GetWorld());
	GridVisual = GetWorld()->SpawnActorDeferred<ASG_Grid>(GridVisualClass, GridOrigin);
	check(GridVisual);
	GridVisual->SetModel(Game->getGrid(), CellSize);
	GridVisual->FinishSpawning(GridOrigin);
}