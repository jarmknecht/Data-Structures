#pragma once
#include "SortFactory.h"
class HeapSort :
	public ISortAlgorithm
{
public:
	HeapSort();
	~HeapSort();

	void SortData(int *data, size_t count);
private:
	void HeapSortShiftDown(int *data, int start, int end);
};

