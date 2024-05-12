// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Types.h"

namespace Snake
{
	class Grid;

	class SNAKEGAME_API Game
	{
	public:
		Game(const Settings& settings);

		TSharedPtr<Grid> getGrid() const { return m_grid;}

	private:
		const Settings c_settings;
		TSharedPtr<Grid> m_grid;
	};
};
