#include "SelectionSort.h"



SelectionSort::SelectionSort()
{
}


SelectionSort::~SelectionSort()
{
}

void SelectionSort::SortData(int *data, size_t count)
{
	for (size_t i = 0; i < count; i++) {
		int min = i;

		for (size_t j = i + 1; j < count; j++) {
			if (data[j] < data[min]) {
				min = j;
			}
		}
		
		if (min != i) {
			SortFactory::Swap(data[min], data[i]);
		}
	}
}
