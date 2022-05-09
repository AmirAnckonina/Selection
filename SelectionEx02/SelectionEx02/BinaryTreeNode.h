#pragma once
#include "Person.h";

class BinaryTreeNode {
private:
	Person* m_PersonData;
	BinaryTreeNode* m_left, * m_right;

	friend class BinaryTree;
public:
	BinaryTreeNode() {};
	BinaryTreeNode(Person i_Person, BinaryTreeNode* i_LeftNode, BinaryTreeNode* i_RightNode) {};
	//~BinaryTreeNode();
};