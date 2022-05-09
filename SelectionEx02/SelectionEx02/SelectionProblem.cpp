#include "SelectionProblem.h"

void SelectionProblem::Run()
{
	RandSelectionProgram randSelection;
	HeapSelectionProgram heapSelection;
	BSTSelectionProgram bstSelection;
	vector<Person*> personArr;
	int numOfPersons = 0;
	int kthPerson;
	
	InputProcedure(personArr, numOfPersons);
	kthPerson = GetKthPerson();

	randSelection.Run(personArr, numOfPersons, kthPerson);
	heapSelection.Run(personArr, numOfPersons, kthPerson);
	bstSelection.Run(personArr, numOfPersons, kthPerson);
}

void SelectionProblem::InputProcedure(vector<Person*>& o_PersonArr, int& o_ArrSize)
{
	Person* newPerson;

	o_ArrSize = GetNumOfPersonsProcedure();

	cout << "Please enter " << o_ArrSize << " pepole:" << endl;
	for (int i = 0; i < o_ArrSize; i++)
	{
		newPerson = SinglePersonInputProcedure(o_PersonArr);
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

	if (IsKeyIDExist(i_PersonArr, i_KeyID))
	{
		throw new exception("Invalid input, ID already exist.");
	}
}

bool SelectionProblem::IsKeyIDExist(vector<Person*> i_PersonArr, int i_KeyID)
{
	for (int i = 0; i < i_PersonArr.size(); i++) {
		if (i_PersonArr[i]->GetKeyID() == i_KeyID)
			return true;
	}

	return false;
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

int SelectionProblem::GetKthPerson()
{
	int reskthPerson;

	/// Add validation that k < NumOfPersons.  
	cout << "Please enter the 'k' largest Person you want by key :";
	cin >> reskthPerson;

	return reskthPerson;
}

