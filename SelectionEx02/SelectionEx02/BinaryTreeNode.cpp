#include "BinaryTreeNode.h"

BinaryTreeNode::BinaryTreeNode(Person* i_Person, BinaryTreeNode* i_LeftNode, BinaryTreeNode* i_RightNode)
{
	m_PersonData = i_Person;
	i_LeftNode = nullptr;
	i_RightNode = nullptr;
}
