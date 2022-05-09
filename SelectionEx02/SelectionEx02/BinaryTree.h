#pragma once
#include "BinaryTreeNode.h"
#include <stdlib.h>
#include <stdio.h>
#include <random>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

class BinaryTree {
	BinaryTreeNode* m_Root;

public:
	BinaryTree() : m_Root(nullptr) {}
	BinaryTree(vector<Person*> i_PersonArr, int& io_NumComp);
	//~BinaryTree();

	BinaryTreeNode* GetRoot() { return m_Root; }

	void MakeEmpty();
	bool IsEmpty();
	Person* Find(int i_PersonKeyID, int& io_NumComp);
	void CreateTreeFromArr(vector<Person*> i_PersonArr, int& io_NumComp);
	void Insert(Person* i_Person, int& io_NumComp);;
	//void Delete(int i_KeyIDToDelete, int& io_NumComp); Needed?!
	//Min(); // Needed?!
	//Max();
	/*Succ();
	Pred();*/
};