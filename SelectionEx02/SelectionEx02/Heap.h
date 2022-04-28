#pragma once
#include "Person.h"

class Heap {
	Person* m_PersonData;
	int m_MaxSize;
	int m_HeapSize;
	int m_Allocated;

	static int Left(int i_Index) { return i_Index * 2 + 1; }
	static int Right(int i_Index) { return i_Index * 2 + 2; }
	static int Parent(int i_Index) { return (i_Index - 1) / 2; }

	void FixHeap(int node);

public:
	Heap(int i_Max);
	Heap(Person i_Person[], int i_Size); // Turn i_Person[] into heap.
	~Heap();

	Person Min();
	Person DeleteMin();
	void Insert(Person i_Person);
	void BuildHeap(); // Using Floyd algorithm.
	void MakeEmpty();
	bool IsEmpty();
};