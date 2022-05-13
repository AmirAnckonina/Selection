#include "SelectionProblem.h"

const string SelectionProblem::EMPTYNAME = "";

void SelectionProblem::Run()
{
	RandSelectionProgram randSelection;
	HeapSelectionProgram heapSelection;
	BSTSelectionProgram bstSelection;
	vector<Person*> personArr;
	int numOfPersons = 0;
	int kthPerson;
	int seed;


	cin >> seed;
	srand(seed);
	InputProcedure(personArr, numOfPersons);
	kthPerson = GetKthPerson(numOfPersons);
	randSelection.Run(personArr, kthPerson);
	heapSelection.Run(personArr, kthPerson);
	bstSelection.Run(personArr, kthPerson);
	FreePersonArr(personArr);
}

void SelectionProblem::InputProcedure(vector<Person*>& o_PersonArr, int& o_NumOfPersons)
{
	Person* newPerson;
	Person* newPersonCopy;
	BinaryTree binaryTreeForKeysValidation;
	int binaryTreeForKeysValidationNumOfComp = 0;
	o_NumOfPersons = GetNumOfPersonsProcedure();

	for (int i = 0; i < o_NumOfPersons; i++)
	{
		newPerson = SinglePersonInputProcedure(o_PersonArr);
		/// The next 2 lines inteded to Validate that the KeyID is unique.
		newPersonCopy = new Person(newPerson->GetKeyID(), EMPTYNAME);
		binaryTreeForKeysValidation.Insert(newPersonCopy, binaryTreeForKeysValidationNumOfComp);
		o_PersonArr.push_back(newPerson);
	}
}

int SelectionProblem::GetNumOfPersonsProcedure()
{
	int numOfPersons;

	cin >> numOfPersons;
	if (numOfPersons < 0)
	{
		cout << "invalid input";
		exit(1);
	}

	cin.ignore();

	return numOfPersons;
}

void SelectionProblem::NameValidation(string i_Name)
{
	if (i_Name.length() == 0) 
	{
		cout << "invalid input";
		exit(1);
	}
}

void SelectionProblem::KeyIDValidation(vector<Person*> i_PersonArr,int i_KeyID)
{

	if (i_KeyID < 0)
	{
		cout << "invalid input";
		exit(1);
	}
}

Person* SelectionProblem::SinglePersonInputProcedure(vector<Person*> i_PersonArr)
{
	string keyIDStr;
	istringstream iss;
	string tempNamePart, fullName, line;
	Person* newPerson;
	int keyID;

	getline(cin, line);
	iss.clear();
	iss.str(line);
	fullName.clear();
	iss >> keyID;
	KeyIDValidation(i_PersonArr, keyID);
	iss >> tempNamePart;
	fullName += tempNamePart;
	while (!iss.eof()) 
	{
		fullName += ' ';
		iss >> tempNamePart;
		fullName += tempNamePart;
	}

	NameValidation(fullName);
	newPerson = new Person(keyID, fullName);

	return newPerson;
}

int SelectionProblem::GetKthPerson(int i_NumOfPersons)
{
	int reskthPerson;

	cin >> reskthPerson;

	if (reskthPerson < 1 || reskthPerson > i_NumOfPersons)
	{
		cout << "invalid input";
		exit(1);
	}

	return reskthPerson;
}

void SelectionProblem::FreePersonArr(vector<Person*>& io_PersonArr)
{
	for (int idx = 0; idx < io_PersonArr.size(); idx++)
	{
		delete io_PersonArr[idx];
	}

	io_PersonArr.clear();
}

