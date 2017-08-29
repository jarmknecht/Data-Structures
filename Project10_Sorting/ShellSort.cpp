#include "ShellSort.h"



ShellSort::ShellSort()
{
}


ShellSort::~ShellSort()
{
}

void ShellSort::SortData(int *data, size_t count)
{
	int gap = count / 2;
	size_t j = 0;

	while (true) {
		for (size_t i = gap; i < count; i++) {
			int temp = data[i];

			for (j = i; j >= gap; j -= gap) {
				if (data[j - gap] > temp) {
					data[j] = data[j - gap];
				}
				else {
					break;
				}
			}
			data[j] = temp;
		}

		if (gap == 1) {
			break;
		}
		gap /= 2;
	}
}
