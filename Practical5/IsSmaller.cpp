#include "IsSmaller.h"
#include "ValueDependantTester.h"
using namespace std;

int IsSmaller::numAliveObjects = 0;

IsSmaller::IsSmaller(int value) : ValueDependantTester(value)
{	
	IsSmaller::numAliveObjects++;	
}

IsSmaller::~IsSmaller()
{	
	IsSmaller::numAliveObjects--;	
}

bool IsSmaller::evaluate(int val)
{	
	if (val < value)
		return true;
	else 
		return false;	
}

NumberTester* IsSmaller::clone()
{	
	NumberTester* newobj = new IsSmaller(value);
	return newobj;	
}

int IsSmaller::getNumAliveObjects()
{	
	return IsSmaller::numAliveObjects;	
}
