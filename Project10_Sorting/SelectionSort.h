#pragma once
#include "SortFactory.h"
class SelectionSort :
	public ISortAlgorithm
{
public:
	SelectionSort();
	~SelectionSort();

	void SortData(int *data, size_t count);
};

