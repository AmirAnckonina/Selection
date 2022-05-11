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

	try
	{
		/*cin >> seed;
		srand(seed);*/
		InputProcedure(personArr, numOfPersons);
		kthPerson = GetKthPerson(numOfPersons);
		randSelection.Run(personArr, kthPerson);
		heapSelection.Run(personArr, kthPerson);
		bstSelection.Run(personArr, kthPerson);
	}
	catch (...)
	{
		exit(1);
	}
}

void SelectionProblem::InputProcedure(vector<Person*>& o_PersonArr, int& o_NumOfPersons)
{
	Person* newPerson;
	Person* newPersonCopy;
	BinaryTree binaryTreeForKeysValidation;
	int binaryTreeForKeysValidationNumOfComp = 0;
	o_NumOfPersons = GetNumOfPersonsProcedure();

	cout << "Please enter " << o_NumOfPersons << " pepole:" << endl;
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

	cout << "Please enter the number of persons: ";
	cin >> numOfPersons;
	if (numOfPersons == NULL)
	{
		throw new exception("Invalid num of persons input");
	}

	cin.ignore();

	return numOfPersons;
}

void SelectionProblem::NameValidation(string i_Name)
{
	if (i_Name.length() == 0) 
	{
		throw new exception("Invalid name!");
	}

	/// Add validation to the chars (contain only letters).
}

void SelectionProblem::KeyIDValidation(vector<Person*> i_PersonArr, int i_KeyID)
{
	/// Check Line content.
	if (i_KeyID == 0) 
	{
		throw new exception("Invalid key ID!");
	}

	//if (IsKeyIDExist(i_PersonArr, i_KeyID))
	//{
	//	throw new exception("Invalid input, ID already exist.");
	//}
}

Person* SelectionProblem::SinglePersonInputProcedure(vector<Person*> i_PersonArr)
{
	int keyID;
	istringstream iss;
	string tempNamePart, fullName, line;
	Person* newPerson;

	cout << "Enter person ID and Name" << endl;
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

	cout << "Please enter the 'k' largest Person you want by key :";
	cin >> reskthPerson;

	if (reskthPerson < 1 || reskthPerson > i_NumOfPersons)
	{
		cout << "Invalid choice. K'th person must be between 1 to " << i_NumOfPersons << endl;
		throw new exception();
	}

	return reskthPerson;
}

