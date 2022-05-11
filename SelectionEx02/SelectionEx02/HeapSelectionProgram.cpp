#include "HeapSelectionProgram.h"

/// Check if the vector sent is as entered in the input procedure
void HeapSelectionProgram::Run(vector<Person*> personArr, int i_KthPerson) 
{
	int numComp = 0;
	Person heapSelectionPerson = SelectHeap(personArr, i_KthPerson, numComp);
	cout << "heapSelection: ";
	heapSelectionPerson.PrintPersonDetails();
	cout << ", comparations: " << numComp << endl;
}

const Person& HeapSelectionProgram::SelectHeap(vector<Person*>& i_PersonArr, int i_KthPerson, int& io_NumComp)
{
	MinHeap minHeap(i_PersonArr, i_PersonArr.size(), io_NumComp); // BuildHeap from array.

	for (int i = 1; i < i_KthPerson; i++)
	{
		minHeap.DeleteMin(io_NumComp);
	}

	return *(minHeap.DeleteMin(io_NumComp));
}
