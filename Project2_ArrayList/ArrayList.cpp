#include "ArrayList.h"

ArrayList::ArrayList()
{
	count = 0;
}

bool ArrayList::Append(int value)
{
	if (GetCount() >= ARRAYLIST_MAX) {
		return false;
	}

	data[count++] = value;
	return true;
}

void ArrayList::Clear()
{
	count = 0;
}

size_t ArrayList::GetCapacity()
{
	return ARRAYLIST_MAX;
}

size_t ArrayList::GetCount()
{
	return count;
}

int ArrayList::GetValue(size_t pos)
{
	if (pos >= GetCount()) {
		return 0;
	}
	return data[pos];
}

bool ArrayList::InsertAt(size_t pos, int value)
{
	if (GetCount() >= ARRAYLIST_MAX) {
		return false;
	}

	if (pos > GetCount()) {
		return false;
	}

	for (size_t i = GetCount(); i > pos; i--) {
		data[i] = data[i - 1];
	}
	data[pos] = value;
	count++;
	return true;
}

bool ArrayList::RemoveAt(size_t pos)
{
	if (pos >= GetCount()) {
		return false;
	}

	for (size_t i = pos; i < GetCount() - 1; i++) {
		data[i] = data[i + 1];
	}
	count--;
	return true;
}

bool ArrayList::SetValue(size_t pos, int value)
{
	if (pos >= GetCount()) {
		return false;
	}
	data[pos] = value;
	return true;
}