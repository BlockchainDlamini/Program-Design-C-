#include "IsPrimeNumber.h"
#include "ValueIndependantTester.h"
using namespace std;

int IsPrimeNumber::numAliveObjects = 0;

IsPrimeNumber::IsPrimeNumber() : ValueIndependantTester()
{	
	IsPrimeNumber::numAliveObjects++;	
}

IsPrimeNumber::~IsPrimeNumber()
{	
	IsPrimeNumber::numAliveObjects--;	
}

bool IsPrimeNumber::evaluate(int val)
{	
	int numfactors = 0;
	
	if (val == 0 || val < 0)
		return false;
		
	for (int i = 1; i < val + 1; i++)		
		if (val % i == 0)
			numfactors++;		
		
	if (numfactors == 2)
		return true;
	else 
		return false;	
}

NumberTester* IsPrimeNumber::clone()
{	
	NumberTester* newobj = new IsPrimeNumber();
	return newobj;	
}

int IsPrimeNumber::getNumAliveObjects()
{	
	return IsPrimeNumber::numAliveObjects;
}
