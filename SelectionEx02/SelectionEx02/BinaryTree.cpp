#include "BinaryTree.h";

BinaryTree::BinaryTree(vector<Person*> i_PersonArr, int& io_NumComp)
{
	CreateTreeFromArr(i_PersonArr, io_NumComp);
}

void BinaryTree::RecursiveDelete(BinaryTreeNode* io_CurrNode)
{
	if (io_CurrNode != nullptr)
	{
		RecursiveDelete(io_CurrNode->m_Left);
		RecursiveDelete(io_CurrNode->m_Right);
		delete io_CurrNode;
	}
}

BinaryTree::~BinaryTree()
{
	RecursiveDelete(m_Root);
}

void BinaryTree::MakeEmpty()
{
	m_Root = nullptr;
}

bool BinaryTree::IsEmpty()
{
	return (m_Root == nullptr);
}

BinaryTreeNode* BinaryTree::Find(int i_PersonKeyID, int& io_NumComp, BinaryTreeNode* o_ParentOfFoundNode)
{
	BinaryTreeNode* curr = m_Root;
	o_ParentOfFoundNode = nullptr;

	while (curr != nullptr) 
	{
		if (i_PersonKeyID == curr->m_PersonData->GetKeyID()) 
		{
			io_NumComp++;
			return curr;
		}

		else
		{
			o_ParentOfFoundNode = curr;
			if (i_PersonKeyID < curr->m_PersonData->GetKeyID()) 
			{
				curr = curr->m_Left;
			}

			else 
			{
				curr = curr->m_Right;
			}

			io_NumComp++;
		}
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
	BinaryTreeNode* temp = m_Root;
	BinaryTreeNode* parent = nullptr;
	BinaryTreeNode* newNode;
	bool leftSon;

	while (temp != nullptr)
	{
		parent = temp; /// Parent saver.
		if (i_Person->GetKeyID() < temp->m_PersonData->GetKeyID())
		{
			temp = temp->m_Left;
			leftSon = true;
		}

		else if ((i_Person->GetKeyID() > temp->m_PersonData->GetKeyID()))
		{
			temp = temp->m_Right;
			leftSon = false;
		}

		else /// Error -> matching keyID
		{
			cout << "Key ID already exist.";
			exit(1);
		}

		io_NumComp++;
	}

	/// After we reached the relevant place to insert the new key: 
	newNode = new BinaryTreeNode(i_Person, nullptr, nullptr);
	if (parent == nullptr)
	{
		m_Root = newNode;
	}

	else
	{
		if (leftSon == true)
		{
			parent->m_Left = newNode;
		}

		else /// rightSon
		{
			parent->m_Right = newNode;
		}
	}
}

void BinaryTree::Delete(int i_KeyIDToDelete, int& io_NumComp)
{
	BinaryTreeNode* nodeToDelete;
	BinaryTreeNode* nodeToDeleteParent = nullptr;

	nodeToDelete = Find(i_KeyIDToDelete, io_NumComp, nodeToDeleteParent);

	// Not found case -> DO nothing.
	if (nodeToDelete == nullptr)
	{
		return;
	}

	// <======================================================>
	// nodeToDelete does not have children.
	if (nodeToDelete->GetLeftNode() == nullptr && nodeToDelete->GetRightNode() == nullptr)
	{
		if (nodeToDelete != m_Root)
		{
			if (nodeToDeleteParent->m_Left == nodeToDelete) 
			{
				nodeToDeleteParent->m_Left = nullptr;
			}

			else 
			{
				nodeToDeleteParent->m_Right = nullptr;
			}
		}

		// if the tree has only a root node, set it to null
		else 
		{
			m_Root = nullptr;
		}

		delete nodeToDelete;
	}

	// Case 2: node to be deleted has two children
	else if (nodeToDelete->m_Left != nullptr && nodeToDelete->m_Right != nullptr)
	{
		// Get minimum key of the right sub-tree, so he will be the successor.
		BinaryTreeNode* successor = GetMinimumKey(nodeToDelete->m_Right);
		/// Update the nodeTo Delete Person Data to the succssor data
		nodeToDelete->SetBinaryNodeData(successor->GetPersonData()); 
		delete successor; /// For sure is a leave, so can be deleted safetly.
	}

	// nodeToDelete has only one child
	else 
	{
		// choose a child node
		BinaryTreeNode* child = (nodeToDelete->m_Left) ? nodeToDelete->m_Left : nodeToDelete->m_Right;
		if (nodeToDelete != m_Root)
		{
			if (nodeToDelete == nodeToDeleteParent->m_Left) 
			{
				nodeToDeleteParent->m_Left = child;
			}
			else {
				nodeToDeleteParent->m_Right = child;
			}
		}

		else 
		{
			m_Root = child;
		}

		delete nodeToDelete;
	}
}

BinaryTreeNode* BinaryTree::GetMinimumKey(BinaryTreeNode* currNode)
{
	BinaryTreeNode* minKeyNode = currNode;
	while (minKeyNode->GetLeftNode() != nullptr)
	{
		minKeyNode = minKeyNode->GetLeftNode();
	}

	return minKeyNode;
}


