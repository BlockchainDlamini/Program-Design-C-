#include "SumArray.h"
using namespace std;

SumArray::SumArray(int ** array, int * sizes , int baseSize) : TwoDArray(array, sizes, baseSize)
{

}

int* SumArray::operator[](int number)
{	
	int** outterarr = *this;
	int* newsizes = *this;
	int* pointer = new int(0);
	int base = *this;

	//cout << "number " <<number<<endl;
	//cout << "number of elements in in sizes[number] "<< newsizes[number];

	if (newsizes != NULL) 
		for (int i = 0 ; i < newsizes[number]; i++)
			*pointer += outterarr[number][i];
	
	return pointer;	
}

