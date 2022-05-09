#pragma once
#include "BinaryTree.h"

class SelectionSolutionTree
{

public:
	const Person& BST(vector<Person*> i_PersonArr, int n, int k, int& NumComp);
	void Run();
	void InputProcedure(vector<Person*>& o_PersonArr, int& o_ArrSize);
	bool IsKeyIDExist(vector<Person*> i_PersonArr, int i_CurrArrSize, int i_KeyID);
};