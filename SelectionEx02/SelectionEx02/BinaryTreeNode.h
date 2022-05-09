#pragma once
#include "Person.h";

class BinaryTreeNode {
private:
	Person* m_PersonData;
	BinaryTreeNode* m_left, * m_Right;

	friend class BinaryTree;
public:
	BinaryTreeNode() {};
	BinaryTreeNode(Person* i_Person, BinaryTreeNode* i_LeftNode, BinaryTreeNode* i_RightNode);

	Person* GetPersonData() { return m_PersonData; }
	BinaryTreeNode* GetLeftNode() { return m_left; }
	BinaryTreeNode* GetRightNode() { return m_Right; }
	//void CreateTreeFromArr(vector<Person*> i_Person, int i_Size, int* io_NumComp);
	//~BinaryTreeNode();
};