#include "BinaryTree.h";

BinaryTree::BinaryTree(vector<Person*> i_PersonArr, int& io_NumComp)
{
	CreateTreeFromArr(i_PersonArr, io_NumComp);
}

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
			io_NumComp++;
			return temp->m_PersonData;
		}
		else if (i_PersonKeyID < temp->m_PersonData->GetKeyID()) {
			temp = temp->m_left;
		}
		else {
			temp = temp->m_Right;
		}

		io_NumComp++;
	}

	return nullptr;
}

void BinaryTree::CreateTreeFromArr(vector<Person*> i_PersonArr, int& io_NumComp)
{
	for (int i = 0; i < i_PersonArr.size(); i++)
	{
		Insert(i_PersonArr[i], io_NumComp);
	}
}


void BinaryTree::Insert(Person* i_Person, int& io_NumComp)
{
	//if (Find(i_Person->GetKeyID(), io_NumComp) != nullptr) {
	//	cout << "Erorr";
	//	exit(1);
	//	//Handle error;
	//}

	BinaryTreeNode* temp = m_Root;
	BinaryTreeNode* parent = nullptr;
	BinaryTreeNode* newNode;

	while (temp != nullptr) {
		parent = temp;
		if (i_Person->GetKeyID() < temp->m_PersonData->GetKeyID())
			temp = temp->m_left;
		else temp = temp->m_Right;

		io_NumComp++;
	}

	newNode = new BinaryTreeNode(i_Person, nullptr, nullptr);
	if (parent == nullptr)
		m_Root = newNode;
	else if (i_Person->GetKeyID() < parent->m_PersonData->GetKeyID())
		parent->m_left = newNode;
	else parent->m_Right = newNode;

	io_NumComp++;
}

//void BinaryTree::Delete(int i_KeyIDToDelete, int& io_NumComp)
//{
//}
