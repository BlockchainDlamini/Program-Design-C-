#ifndef ISDIVISIBLE_H
#define ISDIVISIBLE_H

#include <cstddef>
#include "ValueDependantTester.h"

class IsDivisible : public ValueDependantTester
{
	
private: 
	
	static int numAliveObjects;
	
public:
	
	IsDivisible(int value);
	~IsDivisible();
	
	bool evaluate(int val);
	NumberTester* clone();
	static int getNumAliveObjects();
		
};

#endif

