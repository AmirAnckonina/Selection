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
#include "BinaryTree.h"
#include "BinaryTreeNode.h"

class BSTSelectionProgram
{

public:
	void Run(vector<Person*> personArr, int i_NumOfPersons, int i_KthPerson);
	const Person& BST(vector<Person*> i_PersonArr, int n, int i_KthPersonIdx, int& io_NumComp);
};

