#include "BinaryTreeNode.h"

BinaryTreeNode::BinaryTreeNode(Person* i_Person)
{
	m_PersonData = i_Person;
	m_Left = m_Right = nullptr;
}

void BinaryTreeNode::SetBinaryNodeData(Person* i_PersonData)
{
	Person* temp = this->m_PersonData;
	this->m_PersonData = i_PersonData;
	delete temp;
}

