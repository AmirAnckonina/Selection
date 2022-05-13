#pragma once
#include <vector>
#include "BinaryTreeNode.h"


class BinaryTree 
{
	BinaryTreeNode* m_Root;

public:
	/// C'tors and D'tor
	BinaryTree() : m_Root(nullptr) {}
	BinaryTree(vector<Person*> i_PersonArr, int& io_NumComp);
	~BinaryTree();
	void RecursiveDelete(BinaryTreeNode* io_CurrNode);

	void MakeEmpty();
	bool IsEmpty();
	void CreateTreeFromArr(vector<Person*> i_PersonArr, int& io_NumComp);
	BinaryTreeNode* GetRoot() { return m_Root; } 
	BinaryTreeNode* GetMinimumKey(BinaryTreeNode* currNode);

	/// Implemetation for Find,Delete and Insert
	BinaryTreeNode* Find(int i_PersonKeyID, int& io_NumComp, BinaryTreeNode* o_ParentOfFoundNode);
	void Insert(Person* i_Person, int& io_NumComp);
	void Delete(int i_KeyIDToDelete, int& io_NumComp);
};