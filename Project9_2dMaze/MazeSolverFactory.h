#pragma once

#include "MazeSolverBase.h"

class MazeSolverFactory
{
public:
	static MazeSolverBase *CreateSolver(char *data, int xmax, int ymax);
};

