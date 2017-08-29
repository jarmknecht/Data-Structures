#pragma once
#include "SortFactory.h"
class MergeSort :
	public ISortAlgorithm
{
public:
	MergeSort();
	~MergeSort();

	void SortData(int *data, size_t count);
private:
	void MergeList(int *subArray, int count, int midIdx);
};

