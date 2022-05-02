#include "SelectionProblemSolution.h"

void SelectionSolutionProgram::Run()
{
	InputProcedure();
	m_KthPerson = GetKthPerson();
	Person selectedPerson = SelectionRandWrapper(m_PersonArr, m_NumOfPersons, m_KthPerson);
	selectedPerson.PrintPersonDetails();
}

int SelectionSolutionProgram::GetKthPerson()
{
	int kthPerson;

	cout << "Please enter the 'k' largest Person you want by key :";
	cin >> kthPerson;

	return kthPerson;
}

void SelectionSolutionProgram::InputProcedure()
{

	int keyID;
	istringstream iss;
	string fullName;
	string firstName;
	string lastName;
	string line;


	cout << "Please enter the number of person: ";
	cin >> m_NumOfPersons;
	cin.ignore();

	cout << "Please enter " << m_NumOfPersons << " pepole:" << endl;
	for (int i = 0; i < m_NumOfPersons; i++)
	{
		cout << "Enter " << "#" << i + 1 << " person: [ID, Name]" << endl;
		getline(cin, line);
		iss.clear();
		iss.str(line);
		iss >> keyID;
		iss >> firstName;
		iss >> lastName;
		fullName = firstName + " " + lastName;
		if (IsKeyIDExist(m_PersonArr, keyID))
		{
			cout << "Invalid input, ID already exist." << endl;
			exit(1);
		}
		m_PersonArr.push_back({ keyID, fullName });
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

const Person& SelectionSolutionProgram::SelectionRandWrapper(vector<Person> io_PersonArr, int i_NumOfPersons, int i_KPersonIndex)
{
	m_NumComp = 0;
	return SelectionRand(io_PersonArr, 0, i_NumOfPersons - 1, i_KPersonIndex, m_NumComp);
}

const Person& SelectionSolutionProgram::SelectionRand(vector<Person> io_PersonArr, int i_LeftIndex, int i_RightIndex, int i_KPersonIndex, int& io_NumComp)
{
	int pivotIndex;

	pivotIndex = Partition(io_PersonArr, i_LeftIndex, i_RightIndex);
	if (i_KPersonIndex == pivotIndex + 1)
	{
		return io_PersonArr[pivotIndex];
	}

	else if (i_KPersonIndex < pivotIndex + 1)
	{
		i_RightIndex = pivotIndex - 1;
		return SelectionRand(io_PersonArr, i_LeftIndex, i_RightIndex, i_KPersonIndex, io_NumComp);
	}

	else /// i_KPersonIndex > pivotIndex + 1
	{
		i_LeftIndex = pivotIndex + 1;
		/// i_KPersonIndex -= pivotIndex;
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

	return i_LeftIndex;
}


