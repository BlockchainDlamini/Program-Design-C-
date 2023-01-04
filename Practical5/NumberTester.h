#ifndef NUMBERTESTER_H
#define NUMBERTESTER_H

#include <cstddef>

class NumberTester
{
	
private: 
	
	static int numAliveObjects;
	
public:
	
	NumberTester();
	virtual ~NumberTester();
		
	virtual bool evaluate(int) = 0;
	virtual NumberTester* clone() = 0;
	static int getNumAliveObjects();
		
};

#endif

