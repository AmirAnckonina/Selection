#include "SelectionProblemSolution.h"

void SelectionSolutionProgram::Run()
{
	vector<Person*> personArr;
	int kthPerson;
	int numOfPersons;
	int numComp = 0;
	InputProcedure(personArr, numOfPersons);
	kthPerson = GetKthPerson();
	const Person* selectedPerson = SelectionRandWrapper(personArr, numOfPersons, kthPerson, numComp);
}

const Person* SelectionSolutionProgram::SelectionRandWrapper(vector<Person*>& io_PersonArr, int i_NumOfPersons, int i_KPerson, int& io_NumComp)
{
	/// We're sending the K person minus 1 so we will reach the relevant index.
	io_NumComp = 0;
	return SelectionRand(io_PersonArr, 0, i_NumOfPersons - 1, i_KPerson - 1, io_NumComp);
}

const Person* SelectionSolutionProgram::SelectionRand(vector<Person*>& io_PersonArr, int i_LeftIndex, int i_RightIndex, int i_KPersonIndex, int& io_NumComp)
{
	int pivotIndex;

	pivotIndex = Partition(io_PersonArr, i_LeftIndex, i_RightIndex);
	if (i_KPersonIndex == pivotIndex)
	{
		return io_PersonArr[pivotIndex];
	}

	else if (i_KPersonIndex < pivotIndex)
	{
		i_RightIndex = pivotIndex - 1;
		return SelectionRand(io_PersonArr, i_LeftIndex, i_RightIndex, i_KPersonIndex, io_NumComp);
	}

	else /// i_KPersonIndex > pivotIndex
	{
		i_LeftIndex = pivotIndex + 1;
		return SelectionRand(io_PersonArr, i_LeftIndex, i_RightIndex, i_KPersonIndex, io_NumComp);
	}
}

int SelectionSolutionProgram::Partition(vector<Person*>& io_PersonArr, int i_LeftIndex, int i_RightIndex)
{
	int randomPivot; /// = rand() % (i_RightIndex - i_LeftIndex + 1); /// Check
	randomPivot = i_LeftIndex + (rand() % (i_RightIndex - i_LeftIndex));
	int choosedPivotCurrentIndex;
	bool pivotIsLeftToNonPivot;

	swap(io_PersonArr[randomPivot], io_PersonArr[i_LeftIndex]); /// So now the most left is the pivot and we can start the partition.
	pivotIsLeftToNonPivot = true;
	choosedPivotCurrentIndex = i_LeftIndex;
	while (i_LeftIndex < i_RightIndex)
	{
		if (io_PersonArr[i_LeftIndex]->GetKeyID() > io_PersonArr[i_RightIndex]->GetKeyID())
		{
			swap(io_PersonArr[i_LeftIndex], io_PersonArr[i_RightIndex]);
			if (pivotIsLeftToNonPivot)
			{
				choosedPivotCurrentIndex = i_RightIndex;
				i_LeftIndex++;
				pivotIsLeftToNonPivot = false;
			}

			else
			{
				choosedPivotCurrentIndex = i_LeftIndex;
				i_RightIndex--;
				pivotIsLeftToNonPivot = true;
			}
		}

		else // so we don't need to swap elements.
		{
			if (pivotIsLeftToNonPivot)
			{
				i_RightIndex--;
			}

			else
			{
				i_LeftIndex++;
			}
		}
	}

	return choosedPivotCurrentIndex;
}

void SelectionSolutionProgram::InputProcedure(vector<Person*>& o_PersonArr, int& o_ArrSize)
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

int SelectionSolutionProgram::GetNumOfPersonsProcedure()
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

void SelectionSolutionProgram::NameValidation(string i_Name)
{
	if (i_Name.length() == 0) 
	{
		throw new exception("Invalid name!");
	}

	/// Add validation to the chars (contain only letters).
}

void SelectionSolutionProgram::KeyIDValidation(vector<Person*> i_PersonArr, int i_KeyID)
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

bool SelectionSolutionProgram::IsKeyIDExist(vector<Person*> i_PersonArr, int i_KeyID)
{
	for (int i = 0; i < i_PersonArr.size(); i++) {
		if (i_PersonArr[i]->GetKeyID() == i_KeyID)
			return true;
	}

	return false;
}

Person* SelectionSolutionProgram::SinglePersonInputProcedure(vector <Person*> i_PersonArr)
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

int SelectionSolutionProgram::GetKthPerson()
{
	int reskthPerson;

	cout << "Please enter the 'k' largest Person you want by key :";
	cin >> reskthPerson;

	return reskthPerson;
}

