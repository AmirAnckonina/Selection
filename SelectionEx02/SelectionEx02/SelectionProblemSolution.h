#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <random>
#include <cstdlib>
#include <iostream>

class SelectionSolutionProgram
{



public:
	
	const Person& SelectionRand(Person* io_PersonArr, int i_NumOfPersons, int i_RequestedPersonIndex, int& o_NumComp);
	const Person& SelectionHeap(Person* io_PersonArr, int i_NumOfPersons, int i_RequestedPersonIndex, int& o_NumComp);
	const Person& SelectionBST(Person* io_PersonArr, int i_NumOfPersons, int i_RequestedPersonIndex, int& o_NumComp);
	int Partition(Person* io_PersonArr, int i_LeftIndex, int i_RightIndex);

};