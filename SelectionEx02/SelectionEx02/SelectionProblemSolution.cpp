#include "SelectionProblemSolution.h"

void SelectionSolutionProgram::Run()
{
	vector<Person> personArr = {};
	InputProcedure(personArr);
}

void SelectionSolutionProgram::InputProcedure(vector<Person> o_PersonArr)
{

	int n, keyID;
	int spacePos;
	string name;
	string line;
	string tempsubstr;

	cout << "Please enter the number of person: ";
	cin >> n;

	/// assignVectorOfPersons();

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

bool SelectionSolutionProgram::IsKeyIDExist(vector<Person> i_PersonArr, int i_KeyID)
{
	for (int i = 0; i < i_PersonArr.size(); i++) {
		if (i_PersonArr[i].GetKeyID() == i_KeyID)
			return true;
	}

	return false;
}

const Person& SelectionSolutionProgram::SelectionRandWrapper(vector<Person> io_PersonArr, int i_NumOfPersons, int i_KPersonIndex, int& io_NumComp)
{
	io_NumComp = 0;
	return SelectionRand(io_PersonArr, 0, i_NumOfPersons - 1, i_KPersonIndex, io_NumComp);
}

const Person& SelectionSolutionProgram::SelectionRand(vector<Person> io_PersonArr, int i_LeftIndex, int i_RightIndex, int i_KPersonIndex, int& io_NumComp)
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
		i_KPersonIndex -= pivotIndex;
		return SelectionRand(io_PersonArr, i_LeftIndex, i_RightIndex, i_KPersonIndex, io_NumComp);
	}
}

int SelectionSolutionProgram::Partition(vector<Person> io_PersonArr, int i_LeftIndex, int i_RightIndex)
{
	int randomPivot = rand() % (i_RightIndex - i_LeftIndex + 1); /// Check
	bool pivotIsLeftToNonPivot;
	/// Person personInPivot = io_PersonArr[randomPivot]; 

	swap(io_PersonArr[randomPivot], io_PersonArr[i_LeftIndex]); /// So now the most left is the pivot and we can start the partition.
	pivotIsLeftToNonPivot = true;
	while (i_LeftIndex < i_RightIndex)
	{
		if (io_PersonArr[i_LeftIndex].GetKeyID() > io_PersonArr[i_RightIndex].GetKeyID())
		{
			swap(io_PersonArr[i_LeftIndex], io_PersonArr[i_RightIndex]);
			if (pivotIsLeftToNonPivot)
			{
				i_LeftIndex++;
				pivotIsLeftToNonPivot = false;
			}

			else
			{
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

	return randomPivot;
}


