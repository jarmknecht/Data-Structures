#pragma once
#include "SortFactory.h"
class BubbleSort :
	public ISortAlgorithm
{
public:
	BubbleSort();
	~BubbleSort();

	void SortData(int *data, size_t count);
};

