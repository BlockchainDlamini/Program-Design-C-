#include "IsEvenOdd.h"
#include "ValueIndependantTester.h"
using namespace std;

int IsEvenOdd::numAliveObjects = 0;

IsEvenOdd::IsEvenOdd() : ValueIndependantTester()
{	
	IsEvenOdd::numAliveObjects++;	
}

IsEvenOdd::~IsEvenOdd()
{	
	IsEvenOdd::numAliveObjects--;	
}

bool IsEvenOdd::evaluate(int val)
{	
	if (val % 2 == 0 )
		return true;
	else 
		return false;
}

NumberTester* IsEvenOdd::clone()
{	
	NumberTester* newobj = new IsEvenOdd();
	return newobj;	
}

int IsEvenOdd::getNumAliveObjects()
{	
	return IsEvenOdd::numAliveObjects;	
}
