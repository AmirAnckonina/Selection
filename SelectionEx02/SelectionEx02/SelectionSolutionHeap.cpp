#include "SelectionSolutionHeap.h"

const Person& SelectionSolutionHeap::selectHeap(Person* i_PersonArr, int n, int k, int& io_NumComp)
{
	MinHeap minHeap(i_PersonArr, n, io_NumComp); // BuildHeap from array.

	for (int i = 1; i < k; i++) {
		minHeap.DeleteMin(io_NumComp);
	}

	return *(minHeap.DeleteMin(io_NumComp));
}


void SelectionSolutionHeap::Run()
{
	Person* personArr = nullptr;
	int NumComp = 0, arrSize = 0;
	InputProcedure(&personArr, arrSize);
	Person retVal = selectHeap(personArr, arrSize, 2, NumComp);
}


void SelectionSolutionHeap::InputProcedure(Person** o_PersonArr, int& o_ArrSize)
{
	int numOfPersons, keyID = 99;
	istringstream iss;
	string tempNamePart;
	string fullName;
	string line;

	cout << "Please enter the number of person: ";
	cin >> numOfPersons;
	cin.ignore();

	o_ArrSize = numOfPersons;
	*o_PersonArr = new Person[o_ArrSize];

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

		if (IsKeyIDExist(*o_PersonArr, i, keyID))
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

		(*o_PersonArr)[i].SetKeyID((int)keyID);
		(*o_PersonArr)[i].SetName((string)fullName);
	}
}

bool SelectionSolutionHeap::IsKeyIDExist(Person* i_PersonArr, int i_CurrArrSize, int i_KeyID)
{
	for (int i = 0; i < i_CurrArrSize; i++) {
		if (i_PersonArr[i].GetKeyID() == i_KeyID)
			return true;
	}

	return false;
}
