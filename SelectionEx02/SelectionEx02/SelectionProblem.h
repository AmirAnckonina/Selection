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
#include "RandSelectionProgram.h"
#include "HeapSelectionProgram.h"
#include "BSTSelectionProgram.h"

using namespace std;

class SelectionProblem
{

public:
	static const string EMPTYNAME;
	void Run();
	void InputProcedure(vector<Person*>& o_PersonArr, int& o_numOfPersons);
	int GetNumOfPersonsProcedure();
	Person* SinglePersonInputProcedure(vector <Person*> i_PersonArr);
	void KeyIDValidation(vector<Person*> i_PersonArr, int i_KeyID);
	void NameValidation(string i_Name);
	int GetKthPerson(int i_NumOfPersons);
};
