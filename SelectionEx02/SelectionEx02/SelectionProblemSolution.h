#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <random>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include "Person.h"
#include <vector>
#include <string>

using namespace std;

class SelectionSolutionProgram
{

private:
	vector<Person> m_PersonArr;
	int m_KthPerson;
	int m_NumOfPersons;
	int m_NumComp;

public:
	void Run();
	void InputProcedure();
	int GetKthPerson();
	bool IsKeyIDExist(vector<Person> i_PersonArr, int i_KeyID);
	const Person& SelectionRandWrapper(vector<Person> io_PersonArr, int i_NumOfPersons, int i_RequestedPersonIndex);
	const Person& SelectionRand(vector<Person> io_PersonArr, int i_LeftIndex, int i_RightIndex, int i_KPersonIndex, int& io_NumComp);
	const Person& SelectionHeap(Person* io_PersonArr, int i_NumOfPersons, int i_KPersonIndex, int& io_NumComp);
	const Person& SelectionBST(Person* io_PersonArr, int i_NumOfPersons, int i_KPersonIndex, int& io_NumComp);
	int Partition(vector<Person> io_PersonArr, int i_LeftIndex, int i_RightIndex);

};
