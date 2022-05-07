#pragma once
#include "MinHeap.h"
#include "Person.h"

class SelectionSolutionHeap {

public:
	void Run();
	const Person& selectHeap(vector<Person>& i_PersonArr, int n, int k, int& NumComp);
	void InputProcedure(vector<Person>& o_PersonArr);
	bool IsKeyIDExist(vector<Person> i_PersonArr, int i_KeyID);
};

