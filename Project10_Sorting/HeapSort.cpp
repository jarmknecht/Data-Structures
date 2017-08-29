#include "HeapSort.h"



HeapSort::HeapSort()
{
}


HeapSort::~HeapSort()
{
}

void HeapSort::SortData(int *data, size_t count)
{
	int start = 0;
	int end = 0;

	for (start = (count - 2) / 2; start >= 0; start--) {
		HeapSortShiftDown(data, start, count);
	}
	for (end = count - 1; end > 0; end--) {
		SortFactory::Swap(data[end], data[0]);
		HeapSortShiftDown(data, 0, end);
	}
}

void HeapSort::HeapSortShiftDown(int *data, int start, int end)
{
	int root = start;
	while (root * 2 + 1 < end) {
		int child = 2 * root + 1;
		if ((child + 1 < end) && (data[child] < data[child + 1])) {
			child += 1;
		}
		if (data[root] < data[child]) {
			SortFactory::Swap(data[child], data[root]);
			root = child;
		}
		else {
			return;
		}
	}
}
