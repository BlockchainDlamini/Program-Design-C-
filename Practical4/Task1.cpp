//Include for Task1 testing
#ifndef T1T_CPP
#define T1T_CPP

#include "TwoDArray.h"
#include <iostream>

using namespace std;

namespace Phase1
{
	void runTest()
	{
		const int size = 3;
		int** array = new int*[size];
		int* sizes = new int[size];
		int count = 0;

		//Create array
		for (int i = 0; i < size; i++)
		{
			sizes[i] = size;
			array[i] = new int[size];

			for (int k=0;k<sizes[i];k++)
			{
				array[i][k] = count++;
			}
		}

		//Constructor call
		TwoDArray tester(array, sizes, size);

		//Test operator<<
		cout<<"Contents:\n"<<tester<<endl;

		//Test conversion overloads
		int** othArray = tester;
		int* othSizes = tester;
		int othSize = tester;

		cout<<"Contents of copied array:"<<endl;

		for (int i = 0; i < othSize; i++)
		{
			for (int k = 0; k < othSizes[i]; k++)
				cout<<othArray[i][k]<<" ";

			cout<<endl;
		}

		for (int i = 0; i < size; i++)
		{
			delete [] array[i];
		}

		delete [] array;
		delete [] sizes;
	}


}

#endif
