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
#include "Person.h"
#include "MinHeap.h"

class HeapSelectionProgram
{
public:
	const Person& SelectHeap(vector<Person*> i_PersonArr, int n, int k, int& io_NumComp);
	void Run(vector<Person*> personArr, int i_NumOfPersons, int i_KthPerson);
};

