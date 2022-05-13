#pragma once
#include "MinHeap.h"

class HeapSelectionProgram
{
public:
	void Run(vector<Person*> personArr, int i_KthPerson);
	const Person& SelectHeap(MinHeap& io_MinHeap, int i_KthPerson, int& io_NumComp);
};

