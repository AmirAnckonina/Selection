#include "SelectionSolutionHeap.h"

const Person& SelectionSolutionHeap::selectHeap(vector<Person>& i_PersonArr, int n, int k, int& io_NumComp)
{
	MinHeap minHeap(i_PersonArr, n, io_NumComp); // BuildHeap from array.

	for (int i = 1; i < k; i++) {
		minHeap.DeleteMin(io_NumComp);
	}

	return minHeap.DeleteMin(io_NumComp);

	//resPerson;
}


void SelectionSolutionHeap::Run()
{
	vector<Person> personArr = {};
	int NumComp = 0;
	InputProcedure(personArr);
	Person retVal = selectHeap(personArr, personArr.size(), 2, NumComp);
	cout << "BAS";
}

void SelectionSolutionHeap::InputProcedure(vector<Person>& o_PersonArr)
{
	int n, keyID;
	int spacePos;
	string name;
	string line;
	string tempsubstr;

	cout << "Please enter the number of person: ";
	cin >> n;

	cout << "Please enter " << n << " pepole:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter " << "#" << i + 1 << " person: [ID, Name]" << endl;
		cin >> keyID;
		getline(cin, name);
		if (IsKeyIDExist(o_PersonArr, keyID))
		{
			cout << "Invalid input, ID already exist." << endl;
			exit(1);
		}
		o_PersonArr.push_back({ keyID, name });
	}
}

bool SelectionSolutionHeap::IsKeyIDExist(vector<Person> i_PersonArr, int i_KeyID)
{
	for (int i = 0; i < i_PersonArr.size(); i++) {
		if (i_PersonArr[i].GetKeyID() == i_KeyID)
			return true;
	}

	return false;
}
