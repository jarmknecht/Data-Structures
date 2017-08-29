#include <exception>
using namespace std;

#include "BubbleSort.h"


BubbleSort::BubbleSort()
{
}


BubbleSort::~BubbleSort()
{
}

void BubbleSort::SortData(int *data, size_t count)
{
	bool sorted = false;

	for (size_t i = count; i >= 1; i--) {
		sorted = true;

		for (size_t j = 1; j < i; j++) {
			if (data[j - 1] > data[j]) {
				sorted = false;
				SortFactory::Swap(data[j], data[j - 1]);
			}
		}

		if (sorted) {
			break;
		}
	}
}