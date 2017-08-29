#include "MergeSort.h"



MergeSort::MergeSort()
{
}


MergeSort::~MergeSort()
{
}

void MergeSort::SortData(int *data, size_t count)
{
	if (count < 2) {
		return;
	}
	int m = count / 2;
	SortData(data, m);
	SortData(data + m, count - m);
	MergeList(data, count, m);
}

void MergeSort::MergeList(int *subArray, int count, int midIdx)
{
	int *tmpList = new int[count];

	for (int tmpCount = 0, leftIdx = 0, rightIdx = midIdx; tmpCount < count; tmpCount++) {
		if (rightIdx == count) {
			tmpList[tmpCount] = subArray[leftIdx++];
		}
		else if (leftIdx == midIdx) {
			tmpList[tmpCount] = subArray[rightIdx++];
		}
		else if (subArray[rightIdx] < subArray[leftIdx]) {
			tmpList[tmpCount] = subArray[rightIdx++];
		}
		else {
			tmpList[tmpCount] = subArray[leftIdx++];
		}
	}

	for (int i = 0; i < count; i++) {
		subArray[i] = tmpList[i];
	}
	delete[]tmpList;
}
