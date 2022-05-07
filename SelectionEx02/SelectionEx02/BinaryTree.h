#pragma once
#include "BinaryTreeNode.h"

class BinaryTree {
	BinaryTreeNode* m_Root;

public:
	BinaryTree() : m_Root(nullptr) {}
	//~BinaryTree();

	void MakeEmpty();
	bool IsEmpty();
	Person* Find(int i_PersonKeyID, int& io_NumComp);
	void Insert(Person i_Person, int& io_NumComp);
	//void Delete(int i_KeyIDToDelete, int& io_NumComp); Needed?!
	//Min(); // Needed?!
	//Max();
	/*Succ();
	Pred();*/
};