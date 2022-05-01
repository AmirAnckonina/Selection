#include "MinHeap.h"

const Person& selectHeap(vector<Person> i_PersonArr, int n, int k, int& NumComp);

const Person& selectHeap(vector<Person> i_PersonArr, int n, int k, int& NumComp)
{
	MinHeap minHeap(i_PersonArr, n, NumComp); // BuildHeap from array.

	for (int i = 0; i < k - 1; i++) {
		minHeap.DeleteMin(NumComp);
	}

	return minHeap.DeleteMin(NumComp);
}


//void SelectionSolutionProgram::Run()
//{
//	vector<Person> personArr;
//	InputProcedure(personArr);
//}
//
//void SelectionSolutionProgram::InputProcedure(vector<Person> o_PersonArr)
//{
//
//	int n, keyID;
//	string name;
//
//	cout << "Please enter the number of person: ";
//	cin >> n;
//
//	/// assignVectorOfPersons();
//
//	cout << "Please enter " << n << " pepole:" << endl;
//	for (int i = 0; i < n; i++)
//	{
//		cout << "Enter " << "#" << i + 1 << " person: [ID, Name]" << endl;
//		cin >> keyID >> name;
//		while (IsKeyIDExist(o_PersonArr, n, keyID))
//		{
//			cout << "Invalid input, ID already exist." << endl;
//			exit(1);
//		}
//		o_PersonArr.push_back({ keyID, name });
//	}
//}