// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Types.h"

namespace Snake
{
	class SNAKEGAME_API Grid
	{
	public:
		Grid(const Dim& dim);
		
		Dim dim() const {return c_dim;}
		
	private:
		const Dim c_dim;
		TArray<CellType> m_cells;

		void initWalls();
		void printDebug();
		FORCEINLINE uint32 posToIndex(uint32 x, uint32 y) const;
	};
}

