#include "SelectionSolutionTree.h"

const Person& SelectionSolutionTree::BST(vector<Person*> i_PersonArr, int n, int k, int& io_NumComp)
{
	BinaryTree binaryTree(i_PersonArr, io_NumComp);
	BinaryTreeNode* binaryTreeNode = binaryTree.GetRoot();

	while (binaryTreeNode->GetPersonData()->GetKeyID() != i_PersonArr[k - 1]->GetKeyID())
	{
		if (i_PersonArr[k - 1]->GetKeyID() > binaryTreeNode->GetPersonData()->GetKeyID())
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

	if (binaryTreeNode->GetPersonData()->GetKeyID() != i_PersonArr[k - 1]->GetKeyID())
	{
		io_NumComp++;
		// Handle error.
	}

	return *(binaryTreeNode->GetPersonData());
}

void SelectionSolutionTree::Run()
{
	vector<Person*> personArr;
	int NumComp = 0, arrSize = 0;
	InputProcedure(personArr, arrSize);
	Person retVal = BST(personArr, arrSize, 2, NumComp);
}


void SelectionSolutionTree::InputProcedure(vector<Person*>& o_PersonArr, int& o_ArrSize)
{
	int numOfPersons, keyID = 99;
	istringstream iss;
	string tempNamePart;
	string fullName;
	string line;
	Person* newPerson;

	cout << "Please enter the number of person: ";
	cin >> numOfPersons;
	cin.ignore();

	o_ArrSize = numOfPersons;

	cout << "Please enter " << numOfPersons << " pepole:" << endl;
	for (int i = 0; i < numOfPersons; i++)
	{
		cout << "Enter " << "#" << i + 1 << " person: [ID, Name]" << endl;
		getline(cin, line);
		iss.clear();
		iss.str(line);
		fullName.clear();
		iss >> keyID;

		// Check valid KeyID;
		if (keyID == 0) {
			throw new exception("Invalid key ID!");
		}

		if (IsKeyIDExist(o_PersonArr, i, keyID))
		{
			throw new exception("Invalid input, ID already exist.");
		}

		iss >> tempNamePart;

		fullName += (tempNamePart + ' ');

		while (!iss.eof()) {
			iss >> tempNamePart;
			fullName += (tempNamePart + ' ');
		}

		if (fullName.length() == 0) {
			throw new exception("Invalid name!");
		}

		newPerson = new Person(keyID, fullName);
		o_PersonArr.push_back(newPerson);
		/*newPerson->SetKeyID((int)keyID);
		newPerson->SetName((string)fullName);*/

		//(*o_PersonArr)[i].SetKeyID((int)keyID);
		//(*o_PersonArr)[i].SetName((string)fullName);
	}
}


bool SelectionSolutionTree::IsKeyIDExist(vector<Person*> i_PersonArr, int i_CurrArrSize, int i_KeyID)
{
	for (int i = 0; i < i_CurrArrSize; i++) {
		if (i_PersonArr[i]->GetKeyID() == i_KeyID)
			return true;
	}

	return false;
}
