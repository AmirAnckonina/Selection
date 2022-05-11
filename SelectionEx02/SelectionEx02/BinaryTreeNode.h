#pragma once
#include "Person.h";

class BinaryTreeNode 
{
private:
	Person* m_PersonData;
	BinaryTreeNode* m_Left, * m_Right;

	friend class BinaryTree;
public:
	BinaryTreeNode() { m_PersonData = nullptr; m_Left = m_Right = nullptr; };
	BinaryTreeNode(Person* i_Person, BinaryTreeNode* i_LeftNode, BinaryTreeNode* i_RightNode);

	Person* GetPersonData() { return m_PersonData; }
	BinaryTreeNode* GetLeftNode() { return m_Left; }
	BinaryTreeNode* GetRightNode() { return m_Right; }
	//void CreateTreeFromArr(vector<Person*> i_Person, int i_Size, int* io_NumComp);
	//~BinaryTreeNode();
};