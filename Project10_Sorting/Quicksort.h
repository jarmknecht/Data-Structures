#pragma once
#include "SortFactory.h"
class Quicksort :
	public ISortAlgorithm
{
public:
	Quicksort();
	~Quicksort();

	void SortData(int *data, size_t count);
};

