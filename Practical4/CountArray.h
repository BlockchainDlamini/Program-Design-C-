#ifndef COUNTARRAY_H
#define COUNTARRAY_H

#include "TwoDArray.h"

class CountArray : public TwoDArray
{
	
public: 

	CountArray(int** array, int* sizes, int baseSize);
	int* operator[](int );
	
};
	
#endif	
