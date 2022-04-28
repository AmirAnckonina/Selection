#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <random>
#include <cstdlib>
#include <iostream>
#include "Person.h"
#include <vector>

using namespace std;

class SelectionSolutionProgram
{

public:

	void Run();
	void InputProcedure(vector<Person> o_PersonArr);
	const Person& SelectionRandWrapper(vector<Person> io_PersonArr, int i_NumOfPersons, int i_RequestedPersonIndex, int& io_NumComp);
	const Person& SelectionRand(vector<Person> io_PersonArr, int i_LeftIndex, int i_RightIndex, int i_KPersonIndex, int& io_NumComp);
	const Person& SelectionHeap(Person* io_PersonArr, int i_NumOfPersons, int i_KPersonIndex, int& io_NumComp);
	const Person& SelectionBST(Person* io_PersonArr, int i_NumOfPersons, int i_KPersonIndex, int& io_NumComp);
	int Partition(vector<Person> io_PersonArr, int i_LeftIndex, int i_RightIndex);

};
