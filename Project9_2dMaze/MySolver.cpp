/********************************************
*** PLEASE PUT YOUR NAME IN THE SPACE BELOW:
*** Jonathan Armknecht, Project 9
*** jonathan.armknecht@gmail.com
***
********************************************/

#include <stdlib.h>
#include "MySolver.h"
#include <exception>
using namespace std;

bool MySolver::SolveMaze(int xpos, int ypos)
{
	// TODO: Put your implementation here.
	if (GetCell(xpos, ypos) == 'E') {
		return true;
	}

	MarkCell(true, xpos, ypos);

	if (CanMoveTo(xpos, ypos - 1)) {
		if (SolveMaze(xpos, ypos - 1)) {
			return true;
		}
	}
	if (CanMoveTo(xpos + 1, ypos)) {
		if (SolveMaze(xpos + 1, ypos)) {
			return true;
		}
	}
	if (CanMoveTo(xpos, ypos + 1)) {
		if (SolveMaze(xpos, ypos + 1)) {
			return true;
		}
	}
	if (CanMoveTo(xpos - 1, ypos)) {
		if (SolveMaze(xpos - 1, ypos)) {
			return true;
		}
	}

	MarkCell(false, xpos, ypos);
	return false;
}
