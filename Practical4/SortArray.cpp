#include "SortArray.h"
using namespace std;

SortArray::SortArray (int** array, int* sizes, int baseSize) : TwoDArray(array, sizes, baseSize)
{

}

int* SortArray::operator[](int number)
{	
	int** outterarr = *this;
	int *newsizes = *this;	
	int base = *this;
	int temp = 0; 
 
	for (int i = 0 ; i < newsizes[number] - 1; i++)
	{
	 	for (int j = 0 ; j < newsizes[number] - i - 1; j++)
	 	{
		 	if (outterarr[number][j] > outterarr[number][j+1])
		 	{
				temp = outterarr[number][j+1];
				outterarr[number][j+1] = outterarr[number][j];
				outterarr[number][j] = temp;
			}
		}
	}

	return outterarr[number];
}
