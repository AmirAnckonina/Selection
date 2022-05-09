#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <random>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "MinHeap.h"
#include "Person.h"

class SelectionSolutionHeap {

public:
	const Person& selectHeap(Person* i_PersonArr, int n, int k, int& io_NumComp);
	void Run();
	void InputProcedure(Person** o_PersonArr, int& o_ArrSize);
	bool IsKeyIDExist(Person* i_PersonArr, int i_ArrSize, int i_KeyID);
	//const Person& selectHeap(Person[] i_PersonArr, int n, int k, int& NumComp);
	//void InputProcedure(Person[] o_PersonArr, int* o_ArrSize);
	//bool IsKeyIDExist(Person[] i_PersonArr, int i_ArrSize, int i_KeyID);
};

