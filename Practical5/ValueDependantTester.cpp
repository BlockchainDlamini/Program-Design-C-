#include "ValueDependantTester.h"
#include "NumberTester.h"
using namespace std;

int ValueDependantTester::numAliveObjects = 0;

ValueDependantTester::ValueDependantTester(int val): NumberTester(){

	value = val;
	ValueDependantTester::numAliveObjects++;	
	
}

ValueDependantTester::~ValueDependantTester(){
	
	ValueDependantTester::numAliveObjects--;
}
	

int ValueDependantTester::getNumAliveObjects(){
	
	return ValueDependantTester::numAliveObjects;	
	
}
