#include "IsGreater.h"
#include "ValueDependantTester.h"
using namespace std;

int IsGreater::numAliveObjects = 0;

IsGreater::IsGreater(int value) : ValueDependantTester(value)
{	
	IsGreater::numAliveObjects++;	
}

IsGreater::~IsGreater()
{	
	IsGreater::numAliveObjects--;	
}

bool IsGreater::evaluate(int val)
{	
	if(val > value)
		return true;
	else 
		return false;			
}

NumberTester* IsGreater::clone()
{	
	NumberTester* newobj = new IsGreater(value);
	return newobj;		
}

int IsGreater::getNumAliveObjects()
{	
	return IsGreater::numAliveObjects;
}
