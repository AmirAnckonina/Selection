#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <random>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <vector>
#include "MinHeap.h"

class HeapSelectionProgram
{
public:
	void Run(vector<Person*> personArr, int i_KthPerson);
	const Person& SelectHeap(MinHeap& io_MinHeap, int i_KthPerson, int& io_NumComp);
};

