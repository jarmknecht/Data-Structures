#pragma once
#include "SortFactory.h"
class ShellSort :
	public ISortAlgorithm
{
public:
	ShellSort();
	~ShellSort();

	void SortData(int *data, size_t count);
};

