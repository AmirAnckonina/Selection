#pragma once
#include "BinaryTree.h"

class BSTSelectionProgram
{

public:
	void Run(vector<Person*> i_PersonArr, int i_KthPerson);
	const Person& BSTWrapper(vector<Person*>& i_PersonArr, int i_KthPerson, int& io_NumComp);
	const Person* BST(BinaryTreeNode* io_CurrTNode, int i_KthPerson, int& io_NodesCounter, int& io_NumComp);
};

