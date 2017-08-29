/********************************************
*** PLEASE PUT YOUR NAME IN THE SPACE BELOW:
*** Jonathan Armknecht, Project 7
*** jonathan.armknecht@gmail.com
***
********************************************/
#pragma once

const int ARRAY_MAX = 16;

template <typename Type> 
class PriorityQueue
{
private:
	Type data[ARRAY_MAX];
	size_t count;

	int leftChildIdx(int nodeIdx)
	{
		return 2 * nodeIdx + 1;
	}
	
	int rightChildIdx(int nodeIdx)
	{
		return 2 * nodeIdx + 2;
	}
	
	int parentIdx(int nodeIdx)
	{
		return (nodeIdx - 1) / 2;
	}

	void swap(int& leftIdx, int& rightIdx)
	{
		Type temp = data[leftIdx];
		data[leftIdx] = data[rightIdx];
		data[rightIdx] = temp;
	}

public:
	PriorityQueue()
	{
		count = 0;
	}

	void Enqueue(const Type& newItem)
	{
		if (count >= ARRAY_MAX) {
			throw std::exception("The heap is full. Cannot enqueue!");
		}

		int currIdx = count;
		data[currIdx] = newItem;

		int parIdx = parentIdx(currIdx);
		while (data[currIdx] > data[parIdx]) {
			swap(currIdx, parIdx);
		
			currIdx = parIdx;

			parIdx = parentIdx(currIdx);
		}
		count++;
	}

	Type Dequeue()
	{
		if (count < 1) {
			throw std::exception("No items in the heap. Cannot dequeue!");
		}

		Type item = data[0];
		data[0] = data[count - 1];
		count--;

		int currIdx = 0;
		while (true) {
			int leftIdx = leftChildIdx(currIdx);
			int rightIdx = rightChildIdx(currIdx);

			if (leftIdx >= count) {
				break;
			}

			if (data[currIdx] >= data[leftIdx] && data[currIdx] >= data[rightIdx]) {
				break;
			}

			if (data[leftIdx] > data[rightIdx]) {
				swap(currIdx, leftIdx);
				currIdx = leftIdx;
			}
			else {
				swap(currIdx, rightIdx);
				currIdx = rightIdx;
			}
		}

		return item;
	}

	size_t Count()
	{
		return count;
	}

	void Clear()
	{
		count = 0;
	}
};