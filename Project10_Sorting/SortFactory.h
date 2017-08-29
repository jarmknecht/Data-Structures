#pragma once

enum SortType
{
	SortType_BubbleSort,
	SortType_SelectionSort,
	SortType_InsertionSort,
	SortType_ShellSort,
	SortType_HeapSort,
	SortType_MergeSort,
	SortType_QuickSort
};

class ISortAlgorithm
{
public:
	virtual void SortData(int *data, size_t count) = 0;
};

class SortFactory
{
public:
	static ISortAlgorithm *GetSortAlgorithm(SortType);
	static void Swap(int &left, int &right);
};

