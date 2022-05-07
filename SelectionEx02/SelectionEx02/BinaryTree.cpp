#include "BinaryTree.h";

void BinaryTree::MakeEmpty()
{
}

bool BinaryTree::IsEmpty()
{
	return (m_Root == nullptr);
}

Person* BinaryTree::Find(int i_PersonKeyID, int& io_NumComp)
{
	BinaryTreeNode* temp = m_Root;

	while (temp != nullptr) {
		if (i_PersonKeyID == temp->m_PersonData->GetKeyID()) {
			return temp->m_PersonData;
		}
		else if (i_PersonKeyID < temp->m_PersonData->GetKeyID()) {
			temp = temp->m_left;
		}
		else {
			temp = temp->m_right;
		}
	}

	return nullptr;
}

void BinaryTree::Insert(Person i_Person, int& io_NumComp)
{
	if (Find(i_Person.GetKeyID(), io_NumComp) != nullptr) {
		//Handle error;
	}

	BinaryTreeNode* temp = m_Root;
	BinaryTreeNode* parent = nullptr;
	BinaryTreeNode* newNode;

	while (temp != nullptr) {
		parent = temp;
		if (i_Person.GetKeyID() < temp->m_PersonData->GetKeyID())
			temp = temp->m_left;
		else temp = temp->m_right;
	}

	newNode = new BinaryTreeNode(i_Person, nullptr, nullptr);
	if (parent == nullptr)
		m_Root = newNode;
	else if (i_Person.GetKeyID() < parent->m_PersonData->GetKeyID())
		parent->m_left = newNode;
	else parent->m_right = newNode;
}

//void BinaryTree::Delete(int i_KeyIDToDelete, int& io_NumComp)
//{
//}
