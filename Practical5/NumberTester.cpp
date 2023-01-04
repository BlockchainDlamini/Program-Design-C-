#include "NumberTester.h"
using namespace std;

int NumberTester::numAliveObjects = 0;

NumberTester::NumberTester()
{		
	NumberTester::numAliveObjects++;		
}

NumberTester::~NumberTester()
{	
	NumberTester::numAliveObjects--;			
}

int NumberTester::getNumAliveObjects()
{	
	return NumberTester::numAliveObjects;	
}

