#include "BSTSelectionProgram.h"

void BSTSelectionProgram::Run(vector<Person*> personArr, int i_NumOfPersons, int i_KthPerson)
{
	int NumComp = 0;
	int kthPersonIdx = i_KthPerson - 1;
	Person bstSelectionPerson = BST(personArr, i_NumOfPersons, kthPersonIdx, NumComp);
	/// Printing
}

const Person& BSTSelectionProgram::BST(vector<Person*> i_PersonArr, int n, int i_KthPersonIdx, int& io_NumComp)
{
	BinaryTree binaryTree(i_PersonArr, io_NumComp);
	BinaryTreeNode* binaryTreeNode = binaryTree.GetRoot();

	while (binaryTreeNode->GetPersonData()->GetKeyID() != i_PersonArr[i_KthPersonIdx]->GetKeyID())
	{
		if (i_PersonArr[i_KthPersonIdx]->GetKeyID() > binaryTreeNode->GetPersonData()->GetKeyID())
		{
			// Right
			binaryTreeNode = binaryTreeNode->GetRightNode();
		}

		else
		{
			// Left
			binaryTreeNode = binaryTreeNode->GetLeftNode();
		}

		io_NumComp++;
	}

	if (binaryTreeNode->GetPersonData()->GetKeyID() != i_PersonArr[i_KthPersonIdx]->GetKeyID())
	{
		io_NumComp++;
		// Handle error.
	}

	return *(binaryTreeNode->GetPersonData());
}
