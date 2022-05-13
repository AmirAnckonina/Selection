#pragma once
#include <vector>
#include "Person.h"

class MinHeap
{
	vector<Person*> m_PersonData;
	int m_MaxSize;
	int m_HeapSize;

	static int Left(int i_NodeIndex) { return i_NodeIndex * 2 + 1; }
	static int Right(int i_NodeIndex) { return i_NodeIndex * 2 + 2; }
	static int Parent(int i_NodeIndex) { return (i_NodeIndex - 1) / 2; }

	void FixHeap(int i_Node, int& io_NumComp);
	void Swap(int i_NodeInd1, int i_NodeInd2);

public:
	MinHeap(vector<Person*> i_PersonArr, int i_Size, int& io_NumComp); // Turn i_Person[] into heap.

	Person* Min();
	Person* DeleteMin(int& io_NumComp);
	void Insert(Person* i_NewPerson, int& io_NumComp);
	void BuildHeap(vector<Person*>& i_PersonArr, int i_Size, int& io_NumComp); // Using Floyd algorithm.
	void MakeEmpty();
	bool IsEmpty();
};