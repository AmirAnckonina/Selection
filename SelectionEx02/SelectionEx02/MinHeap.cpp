#include "MinHeap.h"

void MinHeap::FixHeap(int i_NodeIndex, int& io_NumComp)
{
	int minIndex, left = Left(i_NodeIndex), right = Right(i_NodeIndex);

	// Find minimum among i_Node, left and right.
	if (left < m_HeapSize && m_PersonData[left].GetKeyID() < m_PersonData[i_NodeIndex].GetKeyID())
	{
		io_NumComp++;
		minIndex = left;
	}
	else
	{
		minIndex = i_NodeIndex;
	}

	if (right < m_HeapSize && m_PersonData[right].GetKeyID() < m_PersonData[minIndex].GetKeyID())
	{
		io_NumComp++;
		minIndex = right;
	}

	// Swap values if necessary, and continue fixing the heap towards the leaves.
	if (minIndex != i_NodeIndex)
	{
		Swap(i_NodeIndex, minIndex);
		FixHeap(minIndex, io_NumComp);
	}

}

void MinHeap::Swap(int i_NodeInd1, int i_NodeInd2)
{
	Person temp = m_PersonData[i_NodeInd1];

	m_PersonData[i_NodeInd1] = m_PersonData[i_NodeInd2];
	m_PersonData[i_NodeInd2] = temp;
}

MinHeap::MinHeap(Person* i_PersonArr, int i_Size, int& io_NumComp)
{
	BuildHeap(i_PersonArr, i_Size, io_NumComp);
}

MinHeap::~MinHeap()
{
	MakeEmpty();
}

Person& MinHeap::Min()
{
	return m_PersonData[0];
}

Person* MinHeap::DeleteMin(int& io_NumComp)
{
	if (m_HeapSize < 1) {
		cout << "Invalid operaion!" << endl;
		exit(1);
	}

	Person* min = new Person(Min());
	m_HeapSize--;
	m_PersonData[0] = m_PersonData[m_HeapSize - 1]; // minus 1?
	FixHeap(0, io_NumComp);

	return min;
}

void MinHeap::Insert(Person i_NewPerson, int& io_NumComp)
{
	if (m_HeapSize == m_MaxSize) {}

	int i = m_HeapSize;
	m_HeapSize++;

	while ((i > 0) && (m_PersonData[Parent(i)].GetKeyID() > i_NewPerson.GetKeyID()))
	{
		io_NumComp++;
		m_PersonData[i] = m_PersonData[Parent(i)];
		i = Parent(i);
	}

	m_PersonData[i] = i_NewPerson;
}

void MinHeap::BuildHeap(Person* i_PersonArr, int i_Size, int& io_NumComp)
{
	m_HeapSize = m_MaxSize = i_Size;

	m_PersonData = i_PersonArr; // Assign array i_PersonArr[] to data pointer.
	//m_Allocated = 0; // Memory not allocated by heap.

	for (int i = i_Size / 2 - 1; i >= 0; i--) {
		FixHeap(i, io_NumComp);
	}
}

void MinHeap::MakeEmpty()
{
	//delete[] m_PersonData;
}

bool MinHeap::IsEmpty()
{
	return (m_HeapSize == 0) ? true : false;
}
