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
	int n, keyID;
	int spacePos;
	string name;
	string line;
	string tempsubstr;

	cout << "Please enter the number of person: ";
	cin >> n;
	o_ArrSize = n;

	*o_PersonArr = new Person[o_ArrSize];

	cout << "Please enter " << n << " pepole:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter " << "#" << i + 1 << " person: [ID, Name]" << endl;
		cin >> keyID;
		getline(cin, name);
		if (IsKeyIDExist(*o_PersonArr, i, keyID))
		{
			cout << "Invalid input, ID already exist." << endl;
			exit(1);
		}
		(*o_PersonArr)[i].SetKeyID(keyID);
		(*o_PersonArr)[i].SetName(name);
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
