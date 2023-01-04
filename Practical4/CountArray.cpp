#include "CountArray.h"
using namespace std;

CountArray::CountArray(int** array, int* sizes, int baseSize) : TwoDArray(array, sizes, baseSize) 
{

}

int* CountArray::operator[](int number)
{
	int* pointer = new int(0);
	int* newsizes = *this;

	for (int i = 0 ; i < newsizes[number]; i++)
		++(*pointer);
	
	return pointer;
}
