#include "InsertionSort.h"



InsertionSort::InsertionSort()
{
}


InsertionSort::~InsertionSort()
{
}

void InsertionSort::SortData(int *data, size_t count)
{
	for (size_t i = 1; i < count; i++) {

		for (size_t j = i; j > 0; j--) {
			if (data[j - 1] > data[j]) {
				SortFactory::Swap(data[j - 1], data[j]);
			}
			else {
				break;
			}
		}
	}
}
