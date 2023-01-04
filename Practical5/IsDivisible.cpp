#include "IsDivisible.h"
#include "ValueDependantTester.h"
using namespace std;

int IsDivisible::numAliveObjects = 0;

IsDivisible::IsDivisible(int value): ValueDependantTester(value)
{		
	IsDivisible::numAliveObjects++;				
}

IsDivisible::~IsDivisible()
{		
	IsDivisible::numAliveObjects--;		
}

bool IsDivisible::evaluate(int val)
{	
	if (value == 0)
		return false;
		
	if (val % value == 0)
		return true;
	else 
		return false;	
}

int IsDivisible::getNumAliveObjects()
{	
	return IsDivisible::numAliveObjects;	
}

NumberTester* IsDivisible::clone()
{	
	NumberTester* newobj = new IsDivisible(value);
	return newobj;		
}
