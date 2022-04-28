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
	SelectionSolutionProgram selectionProgram;

	selectionProgram.Run();

	return 0;
}
