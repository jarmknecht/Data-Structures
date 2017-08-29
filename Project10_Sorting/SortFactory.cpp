#include <exception>
using namespace std;

#include "SortFactory.h"

// TODO: 
// Add include files for each of your sorting classes here:
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "HeapSort.h"
#include "MergeSort.h"
#include "Quicksort.h"

ISortAlgorithm *SortFactory::GetSortAlgorithm(SortType sortType)
{
	// TODO: 
	// Add cases to this switch statement to return a new instance of each
	// sort class.

	switch (sortType)
	{
		case SortType_BubbleSort:
			return new BubbleSort();

		case SortType_SelectionSort:
			return new SelectionSort();

		case SortType_InsertionSort:
			return new InsertionSort();

		case SortType_ShellSort:
			return new ShellSort();

		case SortType_HeapSort:
			return new HeapSort();

		case SortType_MergeSort:
			return new MergeSort();

		case SortType_QuickSort:
			return new Quicksort();
	}

	return nullptr;
}

void SortFactory::Swap(int & left, int & right)
{
	int tmp = left;
	left = right;
	right = tmp;
}