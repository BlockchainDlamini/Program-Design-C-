#ifndef TESTERINTERFACE_H
#define TESTERINTERFACE_H

#include <cstddef>
#include "NumberTester.h"

class TesterInterface
{
	
private:
	
	int maxNumTesters;
	int currNumTesters;
	NumberTester** testers; 
			
public:
	
	TesterInterface(int);
	TesterInterface(TesterInterface*);
	TesterInterface(TesterInterface&);
	~TesterInterface();
	
	int addTester(NumberTester*);
	bool removeTester(int);
	bool evaluate(int);
	int* failedTests(int);
	int numberOfFailedTests(int);
	NumberTester* operator[](int);
	int getCurrNumTesters() const;
	int getMaxNumTesters() const;
	 
};

#endif
