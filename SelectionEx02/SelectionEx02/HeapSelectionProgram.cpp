#include "HeapSelectionProgram.h"

void HeapSelectionProgram::Run(vector<Person*> personArr, int i_NumOfPersons, int i_KthPerson)
{
	int NumComp = 0;
	Person heapSelectionPerson = SelectHeap(personArr, i_NumOfPersons, i_KthPerson, NumComp);
	/// Printing
}

const Person& HeapSelectionProgram::SelectHeap(vector<Person*> i_PersonArr, int n, int k, int& io_NumComp)
{
	MinHeap minHeap(i_PersonArr, n, io_NumComp); // BuildHeap from array.

	for (int i = 1; i < k; i++) {
		minHeap.DeleteMin(io_NumComp);
	}

	return *(minHeap.DeleteMin(io_NumComp));
}
