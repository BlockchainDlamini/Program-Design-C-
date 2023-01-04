//The base 2D array class
#ifndef TWODARRAY_H
#define TWODARRAY_H

#include <iostream>
#include <string>
#include <ostream>

class TwoDArray;
std::ostream& operator<<(std::ostream& os,TwoDArray& tda);

class TwoDArray
{

private:

	int** array;
	int* sizes;
	int baseSize;

public:

	TwoDArray(int **array, int*sizes, int baseSize);
	~TwoDArray();
	//virtual int* operator[](int) = 0;
	operator int();
	operator int*();
	operator int**();
	friend std::ostream& operator <<(std::ostream& os, TwoDArray& tda);

	protected: 

	int** getArray();
	int* getSizes();
	int getBaseSize();


};

#endif
