#include "RandSelectionProgram.h"

void RandSelectionProgram::Run(vector<Person*> personArr, int i_NumOfPersons, int i_KthPerson)
{
	int numComp = 0;
	Person randSelectionPerson = RandSelectionWrapper(personArr, i_NumOfPersons, i_KthPerson, numComp);
	cout << "NumComp RandSelection: " << numComp << endl;
	/// printing.
}

const Person& RandSelectionProgram::RandSelectionWrapper(vector<Person*>& io_PersonArr, int i_NumOfPersons, int i_KPerson, int& io_NumComp)
{
	/// We're sending the K person minus 1 so we will reach the relevant index.
	int kthPersonIdx = i_KPerson - 1;
	io_NumComp = 0;
	return *(RandSelection(io_PersonArr, 0, i_NumOfPersons - 1, kthPersonIdx, io_NumComp));
}

const Person* RandSelectionProgram::RandSelection(vector<Person*>& io_PersonArr, int i_LeftIndex, int i_RightIndex, int i_KPersonIndex, int& io_NumComp)
{
	int pivotIndex;

	pivotIndex = Partition(io_PersonArr, i_LeftIndex, i_RightIndex, io_NumComp);
	if (i_KPersonIndex == pivotIndex)
	{
		return io_PersonArr[pivotIndex];
	}

	else if (i_KPersonIndex < pivotIndex)
	{
		i_RightIndex = pivotIndex - 1;
		return RandSelection(io_PersonArr, i_LeftIndex, i_RightIndex, i_KPersonIndex, io_NumComp);
	}

	else /// i_KPersonIndex > pivotIndex
	{
		i_LeftIndex = pivotIndex + 1;
		return RandSelection(io_PersonArr, i_LeftIndex, i_RightIndex, i_KPersonIndex, io_NumComp);
	}
}

int RandSelectionProgram::Partition(vector<Person*>& io_PersonArr, int i_LeftIndex, int i_RightIndex, int& io_NumComp)
{
	int choosedPivotCurrentIndex;
	bool pivotIsLeftToNonPivot;
	int randomPivot = i_LeftIndex + (rand() % (i_RightIndex - i_LeftIndex));

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

		else /// so we don't need to swap elements.
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
		io_NumComp++;
	}

	return choosedPivotCurrentIndex;
}
