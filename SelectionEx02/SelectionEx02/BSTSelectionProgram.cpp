#include "BSTSelectionProgram.h"

void BSTSelectionProgram::Run(vector<Person*> i_PersonArr, int i_KthPerson)
{
	int numComp = 0;
	Person bstSelectionPerson = BSTWrapper(i_PersonArr, i_KthPerson, numComp);
	cout << "BST: ";
	bstSelectionPerson.PrintPersonDetails();
	cout << numComp << " comparisons";
}

const Person& BSTSelectionProgram::BSTWrapper(vector<Person*>& i_PersonArr, int i_KthPerson, int& io_NumComp)
{
	BinaryTree binaryTree(i_PersonArr, io_NumComp);
	BinaryTreeNode* currTNode = binaryTree.GetRoot();
	int nodesCounter = 0;
	return *(BST(currTNode, i_KthPerson, nodesCounter, io_NumComp));
}

const Person* BSTSelectionProgram::BST(BinaryTreeNode* io_CurrTNode, int i_KthPerson, int& io_NodesCounter, int& io_NumComp)
{
	const Person* resLeft;

	if (io_CurrTNode == nullptr)
	{
		return nullptr;
	}

	resLeft = BST(io_CurrTNode->GetLeftNode(), i_KthPerson, io_NodesCounter, io_NumComp);

	if (resLeft == nullptr)
	{
		io_NodesCounter++;
		if (io_NodesCounter == i_KthPerson)
		{
			return io_CurrTNode->GetPersonData();
		}

		else
		{
			return BST(io_CurrTNode->GetRightNode(), i_KthPerson, io_NodesCounter, io_NumComp);
		}
	}

	else
	{
		return resLeft;
	}
}
