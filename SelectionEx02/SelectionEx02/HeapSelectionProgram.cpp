#include "HeapSelectionProgram.h"

/// Check if the vector sent is as entered in the input procedure
void HeapSelectionProgram::Run(vector<Person*> personArr, int i_KthPerson) 
{
	int numComp = 0;
	MinHeap minHeap(personArr, personArr.size(), numComp); // BuildHeap from array.
	Person heapSelectionPerson = SelectHeap(minHeap, i_KthPerson, numComp);
	cout << "heapSelection: ";
	heapSelectionPerson.PrintPersonDetails();
	cout << ", comparations: " << numComp << endl;
}

const Person& HeapSelectionProgram::SelectHeap(MinHeap& io_MinHeap, int i_KthPerson, int& io_NumComp)
{
	for (int i = 1; i < i_KthPerson; i++)
	{
		io_MinHeap.DeleteMin(io_NumComp);
	}

	return *(io_MinHeap.DeleteMin(io_NumComp));
}
