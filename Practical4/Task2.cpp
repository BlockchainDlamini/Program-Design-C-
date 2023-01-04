//Include for Task2 testing
#ifndef T2T_CPP
#define T2T_CPP

#include "CountArray.h"
#include "SumArray.h"
#include "SortArray.h"

using namespace std;

namespace Phase2 
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

			for (int k = 0; k <sizes[i]; k++)
			{
				array[i][k] = count++;
			}
		}

		//Constructor call
		CountArray tester1(array, sizes, size);
		SumArray tester2(array, sizes, size);
		SortArray tester3(array, sizes, size);



		for (int i = 0; i < size; i++)
		{
			cout<<"Count: "<<*tester1[i]<<endl;
			cout<<"Sum: "<<*tester2[i]<<endl;
			int* arr = tester3[i];

			cout<<"Sorted: "<<endl;
			for (int k = 0; k < sizes[i]; k++)
				cout<<arr[k]<<" ";
			cout<<endl<<endl;
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
