#include <stdlib.h>
#include <stdio.h>
#include "SelectionProblemSolution.h"

#include "Person.h"

bool IsKeyIDExist(vector<Person> i_PersonArr, int i_ArrSize, int i_KeyID)
{
	for (int i = 0; i < i_ArrSize; i++) {
		if (i_PersonArr[i].GetKeyID() == i_KeyID)
			return false;
	}

	return true;
}

int main()
{
	int n, keyID;
	string name;
	vector<Person> personArr;

	cout << "Please enter the number of person: ";
	cin >> n;

	cout << "Please enter " << n << " pepole:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter " << "#" << i + 1 << " person: [ID, Name]" << endl;
		cin >> keyID >> name;
		while (IsKeyIDExist(personArr, n, keyID))
		{
			cout << "Invalid input, ID already exist." << endl;
			exit(1);
		}
		personArr.push_back({ keyID, name });
	}


	return 0;
}
