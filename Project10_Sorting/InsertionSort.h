#pragma once
#include "SortFactory.h"
class InsertionSort :
	public ISortAlgorithm
{
public:
	InsertionSort();
	~InsertionSort();

	void SortData(int *data, size_t count);
};

