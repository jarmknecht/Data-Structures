#pragma once

#include <iostream>

class MazeSolverBase
{
private:
	char *_maze;
	int _xmax;
	int _ymax;

public:
	MazeSolverBase(char *data, int xmax, int ymax) :
		_maze(data),
		_xmax(xmax),
		_ymax(ymax)
	{}


	////////////////////////////////////////////////////////
	// Use this method to tell whether or not you can move 
	// to a specific cell.
	bool CanMoveTo(int x, int y)
	{
		if (x < 0 || x >= _xmax)
			return false;
		if (y < 0 || y >= _ymax)
			return false;

		char ch = *(_maze + (y * _xmax + x));
		return (ch == ' ' || ch == 'E');
	}


	///////////////////////////////////////////////////////////
	// Use this method to get the value of any cell in the 
	// maze.  If the cell is a space (char 32), you can move
	// into it.  If the cell is an 'E', then you have found the 
	// exit.  If the cell has ANY other value, then you can not
	// move into it.
	char GetCell(int x, int y)
	{
		return *(_maze + (y * _xmax + x));
	}


	///////////////////////////////////////////////////////////
	// Use this method to mark a cell that you have visited.
	// You can use any character you like, but you should 
	// avoid using a wall character '#' or an 'E'.
	void MarkCell(bool isVisited, int x, int y)
	{
		char ch = isVisited ? '+' : ' ';
		*(_maze + (y * _xmax + x)) = ch;
	}

	
	///////////////////////////////////////////////////////////
	// Gets the width of the maze.  You probably won't need 
	// this, since all the edges of the maze will be lined with
	// wall characters.
	size_t GetWidth()
	{
		return _xmax;
	}


	///////////////////////////////////////////////////////////
	// Gets the height of the maze.  You probably won't need 
	// this, since all the edges of the maze will be lined with
	// wall characters.
	size_t GetHeight()
	{
		return _ymax;
	}


	///////////////////////////////////////////////////////////
	// TODO: This is the method that you need to implement.
	virtual bool SolveMaze(int xpos, int ypos) = 0;


	///////////////////////////////////////////////////////////
	// This method will print out the maze.
	void Print()
	{
		std::cout << std::endl;
		for (int row = 0; row < _ymax; row++)
		{
			std::cout << "          ";
			for (int col = 0; col < _xmax; col++)
				std::cout << *(_maze + (row * _xmax + col));
			std::cout << std::endl;
		}

		std::cout << std::endl << std::endl;
	}
};
