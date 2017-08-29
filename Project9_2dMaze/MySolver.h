#pragma once

#include "MazeSolverBase.h"

class MySolver: public MazeSolverBase
{
public:
	MySolver(char * data, int width, int height) :
		MazeSolverBase(data, width, height)
	{}

	bool SolveMaze(int xpos, int ypos);
};
