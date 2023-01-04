#ifndef VALUEINDEPENDANTTESTER_H
#define VALUEINDEPENDANTTESTER_H

#include <cstddef>
#include "NumberTester.h"

class ValueIndependantTester : public NumberTester
{
	
private: 
	
	static int numAliveObjects;
	
public: 
	
	ValueIndependantTester();
	virtual ~ValueIndependantTester();
	
	virtual bool evaluate(int) = 0;
	virtual NumberTester* clone() = 0;
	static int getNumAliveObjects();
		
};

#endif

