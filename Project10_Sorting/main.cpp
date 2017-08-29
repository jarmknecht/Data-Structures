#include <iostream>
#include <exception>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "SortFactory.h"
#include "TestCase.h"

void SetArray(int *data, size_t size)
{
	srand(time(nullptr));
	for (size_t i = 0; i < size; i++)
		data[i] = rand();
}

void ValidateSortAscending(TestCase &tc, int *data, size_t count)
{
	for (size_t i = 1; i < count; i++)
	{
		if (data[i] < data[i-1])
		{
			stringstream ss;
			ss << "Data is out of position starting at index " << i;
			tc.LogResult(RESULT_FAILED, ss.str().c_str());
			return;
		}
	}

	tc.LogResult(RESULT_PASSED, "All data is sorted.");
}

void TestSort(char *title, SortType sortType)
{
	TestCase tc(title);

	int data[100];
	SetArray(data, 100);

	ISortAlgorithm *alg = NULL;
	try
	{
		alg = SortFactory::GetSortAlgorithm(sortType);
		alg->SortData(data, 100);

		ValidateSortAscending(tc, data, 100);
	}
	catch (exception &ex)
	{
		tc.LogException(ex);
	}

	if (alg != NULL)
		delete alg;
}

void main()
{
	TestSort("Test bubble sort.", SortType_BubbleSort);
	TestSort("Test selection sort.", SortType_SelectionSort);
	TestSort("Test insertion sort.", SortType_InsertionSort);
	TestSort("Test shell sort.", SortType_ShellSort);
	TestSort("Test heap sort.", SortType_HeapSort);
	TestSort("Test merge sort.", SortType_MergeSort);
	TestSort("Test quick sort.", SortType_QuickSort);

	TestCase::PrintSummary();
}