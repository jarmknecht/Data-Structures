//Jonathan Armknecht Project 1

#include "ArrayTools.h"

ArrayTools::ArrayTools()
{
}


ArrayTools::~ArrayTools()
{
}

int ArrayTools::CountAllOccurrences(int data[], size_t length, int x)
{
	int numOfOccurrences = 0;

	if (length <= 0) {
		return numOfOccurrences;
	}
	else {
		for (size_t i = 0; i < length; i++) {
			if (data[i] == x) {
				numOfOccurrences++;
			}
		}
	}
	return numOfOccurrences;
}

void ArrayTools::Reverse(int data[], size_t length)
{
	int tempVal = 0;

	if (length <= 0) {
		return;
	}
	else {
		for (size_t i = 0; i < length / 2; i++) {
			tempVal = data[i];
			data[i] = data[length - 1 - i];
			data[length - 1 - i] = tempVal;
		}
	}
}

size_t ArrayTools::RemoveAllOccurrences(int data[], size_t length, int x)
{
	size_t count = 0;
	const int ARRAY_MAX = 100;
	int newData[ARRAY_MAX];

	if (length <= 0) {
		return count;
	}
	else {
		for (size_t i = 0; i < length; i++) {
			if (data[i] != x) {
				newData[count] = data[i];
				count++;
			}
		}
		for (size_t i = 0; i < count; i++) {
			data[i] = newData[i];
		}
	}
	return count;
}

size_t ArrayTools::RemoveDuplicates(int data[], size_t length)
{
	const int ARRAY_MAX = 100;
	int newData[ARRAY_MAX];
	size_t newCount = 0;
	bool duplicateFound = false;

	if (length <= 0) {
		return newCount;
	}
	else {
		for (size_t i = 0; i < length; i++) {
			duplicateFound = false;
			for (size_t j = 0; j < length; j++) {
				if (newData[j] == data[i]) {
					duplicateFound = true;
				}
			}
			if (!duplicateFound) {
				newData[newCount] = data[i];
				newCount++;
			}
		}
		for (size_t i = 0; i < newCount; i++) {
			data[i] = newData[i];
		}
	}
	return newCount;
}

size_t ArrayTools::Intersect(int data1[], size_t length1, int data2[], size_t length2, int result[], size_t resultMax)
{
	size_t resultCount = 0;
	bool foundNum = false;
	size_t numberOfDuplicates = 0;
	size_t sizeOfResultArray = 0;

	if (length1 <= 0) {
		return resultCount;
	}
	if (length2 <= 0) {
		return resultCount;
	}

	if (length1 > length2) {
		for (size_t i = 0; i < length1; i++) {
			numberOfDuplicates += CountAllOccurrences(data2, length2, data1[i]);
		}
	}
	else if (length2 > length1) {
		for (size_t i = 0; i < length2; i++) {
			numberOfDuplicates += CountAllOccurrences(data1, length1, data2[i]);
		}
	}
	else if (length1 == length2) {
		for (size_t i = 0; i < length1; i++) {
			numberOfDuplicates += CountAllOccurrences(data2, length2, data1[i]);
		}
	}

	sizeOfResultArray = numberOfDuplicates;

	if (sizeOfResultArray > resultMax) {
		return BUFF_OVERFLOW;
	}
	
	for (size_t i = 0; i < length1; i++) {
		foundNum = false;
		for (size_t j = 0; j < length2; j++) {
			if (data1[i] == data2[j]) {
				foundNum = true;
				break;
			}
		}
		if (foundNum) {
			if (resultCount < resultMax) {
				result[resultCount] = data1[i];
				resultCount++;
			}
			else if (resultCount > resultMax) {
				return BUFF_OVERFLOW;
			}
		}
		if (resultCount > resultMax) {
			return BUFF_OVERFLOW;
		}
	}

	return resultCount;
}

size_t ArrayTools::Union(int data1[], size_t length1, int data2[], size_t length2, int result[], size_t resultMax)
{
	size_t sizeOfResultArray = 0;
	size_t resultCount = 0;
	size_t numberOfDuplicates = 0;
	bool foundNumIn1 = false;
	bool foundNumIn2 = false;
	bool duplicatesInSamePos = false;

	if (length1 <= 0) {
		return resultCount;
	}
	if (length2 <= 0) {
		return resultCount;
	}

	if (length1 > length2) {
		for (size_t i = 0; i < length1; i++) {
			numberOfDuplicates += CountAllOccurrences(data2, length2, data1[i]);
		}
	}
	else if (length2 > length1) {
		for (size_t i = 0; i < length2; i++) {
			numberOfDuplicates += CountAllOccurrences(data1, length1, data2[i]);
		}
	}
	else if (length1 == length2) {
		for (size_t i = 0; i < length1; i++) {
			numberOfDuplicates += CountAllOccurrences(data2, length2, data1[i]);
		}
	}

	sizeOfResultArray = (length1 + length2) - numberOfDuplicates;

	if (sizeOfResultArray > resultMax) {
		return BUFF_OVERFLOW;
	}
	
	for (size_t i = 0; resultCount < sizeOfResultArray; i++) {
		foundNumIn1 = false;
		foundNumIn2 = false;
		duplicatesInSamePos = false;
		for (size_t j = 0; j < sizeOfResultArray; j++) {
			if (result[j] == data1[i]) {
				foundNumIn1 = true;
			}
			if (result[j] == data2[i]) {
				foundNumIn2 = true;
			}
			if (data1[i] == data2[i]) {
				duplicatesInSamePos = true;
			}
		}
		if (duplicatesInSamePos) {
			if (resultCount < resultMax) {
				result[resultCount++] = data1[i];
			}
			else if (resultCount > resultMax) {
				return BUFF_OVERFLOW;
			}
		}
		else if (!foundNumIn1 && foundNumIn2) {
			if (resultCount < resultMax) {
				if (i < length1) {
					result[resultCount++] = data1[i];
				}
			}
			else if (resultCount > resultMax) {
				return BUFF_OVERFLOW;
			}
		}
		else if (!foundNumIn2 && foundNumIn1) {
			if (resultCount < resultMax) {
				if (i < length2) {
					result[resultCount++] = data2[i];
				}
			}
			else if (resultCount > resultMax) {
				return BUFF_OVERFLOW;
			}
		}
		else if (!foundNumIn1 && !foundNumIn2) {
			if (resultCount < resultMax) {
				if (i < length1) {
					result[resultCount++] = data1[i];
				}
				if (i < length2) {
					result[resultCount++] = data2[i];
				}
				if (resultCount > resultMax) {
					return BUFF_OVERFLOW;
				}
			}
		}
		if (resultCount > resultMax) {
			return BUFF_OVERFLOW;
		}
	}
	
	return resultCount;
}
