#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <random>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "Person.h"

class RandSelectionProgram
{

public:
	void Run(vector<Person*> personArr, int i_KthPerson);
	const Person& RandSelectionWrapper(vector<Person*>& io_PersonArr, int i_KthPerson, int& io_NumComp);
	const Person* RandSelection(vector<Person*>& io_PersonArr, int i_LeftIndex, int i_RightIndex, int i_KPersonIndex, int& io_NumComp);
	int Partition(vector<Person*>& io_PersonArr, int i_LeftIndex, int i_RightIndex, int& io_NumComp);
};

