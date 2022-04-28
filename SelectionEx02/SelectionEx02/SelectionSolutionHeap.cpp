#include "MinHeap.h"

const Person& selectHeap(vector<Person> i_PersonArr, int n, int k, int& NumComp);

const Person& selectHeap(vector<Person> i_PersonArr, int n, int k, int& NumComp)
{
	MinHeap minHeap(i_PersonArr, n, NumComp); // BuildHeap from array.

	for (int i = 0; i < k - 1; i++) {
		minHeap.DeleteMin(NumComp);
	}

	return minHeap.DeleteMin(NumComp);
}