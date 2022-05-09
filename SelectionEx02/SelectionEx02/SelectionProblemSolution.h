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

using namespace std;

class SelectionSolutionProgram
{

private:
	/*vector<Person> m_PersonArr;
	int m_KthPerson;
	int m_NumOfPersons;
	int m_NumComp;*/

public:
	void Run();
	void InputProcedure(vector<Person*>& o_PersonArr, int& o_numOfPersons);
	int GetKthPerson();
	bool IsKeyIDExist(vector<Person*> i_PersonArr, int i_KeyID);
	const Person* SelectionRandWrapper(vector<Person*>& io_PersonArr, int i_NumOfPersons, int i_KPerson, int& io_NumComp);
	const Person* SelectionRand(vector<Person*>& io_PersonArr, int i_LeftIndex, int i_RightIndex, int i_KPersonIndex, int& io_NumComp);
	/*const Person& SelectionHeap(vector<Person*> io_PersonArr, int i_NumOfPersons, int i_KPersonIndex, int& io_NumComp);
	const Person& SelectionBST(vector<Person*> io_PersonArr, int i_NumOfPersons, int i_KPersonIndex, int& io_NumComp);*/
	int Partition(vector<Person*>& io_PersonArr, int i_LeftIndex, int i_RightIndex);
	int GetNumOfPersonsProcedure();
	Person* SinglePersonInputProcedure(vector <Person*> i_PersonArr);
	void KeyIDValidation(vector<Person*> i_PersonArr, int i_KeyID);
	void NameValidation(string i_Name);

};
