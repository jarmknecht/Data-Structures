#include "Quicksort.h"



Quicksort::Quicksort()
{
}


Quicksort::~Quicksort()
{
}

void Quicksort::SortData(int *data, size_t count)
{
	int i = 0;
	int j = 0;
	int pivotVal = 0;

	if (count < 2) {
		return;
	}
	pivotVal = data[count / 2];

	for (i = 0; j = count - 1; i++, j--) {
		while (data[i] < pivotVal) {
			i++;
		}
		while (pivotVal < data[j]) {
			j--;
		}
		if (i >= j) {
			break;
		}
		SortFactory::Swap(data[i], data[j]);
	}
	SortData(data, i);
	SortData(data + i, count - i);
}
