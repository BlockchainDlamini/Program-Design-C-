#include "ValueIndependantTester.h"
#include "NumberTester.h"
using namespace std;

int ValueIndependantTester::numAliveObjects = 0;


ValueIndependantTester::ValueIndependantTester(): NumberTester(){
	
	ValueIndependantTester::numAliveObjects++;	
	
}

ValueIndependantTester::~ValueIndependantTester(){
	
	ValueIndependantTester::numAliveObjects--;	
		
}

int ValueIndependantTester::getNumAliveObjects(){
	
	return ValueIndependantTester::numAliveObjects;
	
}
