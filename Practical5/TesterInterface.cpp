#include "TesterInterface.h"
#include "NumberTester.h"
using namespace std;

TesterInterface::TesterInterface(int maxNumTesters)
{	
	if (maxNumTesters < 1)
	{
		this->maxNumTesters = 0;
		currNumTesters = 0;
		testers = new NumberTester*[0];
	}
	else
	{	 
		this->maxNumTesters = maxNumTesters;
		currNumTesters = 0;
		testers = new NumberTester*[this->maxNumTesters];
	
		for (int i = 0; i < this->maxNumTesters; i++)
			testers[i] = NULL;
	}	
}

TesterInterface::TesterInterface(TesterInterface* other)
{	
	if (other == NULL)
	{
		maxNumTesters = 0;
		currNumTesters = 0;
		testers = new NumberTester*[0];
	}
	else
	{
		maxNumTesters = other->maxNumTesters;
		currNumTesters = other->currNumTesters;
		testers = new NumberTester*[maxNumTesters];
			  
		for (int i = 0; i < maxNumTesters; i++)
		{
			if (other->testers[i] != NULL) 
			//clone function creates a deep copy of the required tester object
				testers[i] = other->testers[i]->clone();
			else 
				testers[i] = NULL;
		}	
	}	
}

TesterInterface::TesterInterface(TesterInterface& other)
{
	maxNumTesters = other.maxNumTesters;
	currNumTesters = other.currNumTesters;
	testers = new NumberTester*[maxNumTesters];
			  
	for (int i = 0; i < maxNumTesters; i++)
	{
		if (other.testers[i] != NULL)
			testers[i] = other.testers[i]->clone(); 
		else 
			testers[i] = NULL;
	}
}

TesterInterface::~TesterInterface()
{	
	if (maxNumTesters == 0)
		delete [] testers;
	else
	{
		for (int i = 0; i < maxNumTesters; i++)
			if (testers[i] != NULL)
				delete testers[i];
		
		delete [] testers;
	}
}

int TesterInterface::addTester(NumberTester* tester)
{
	if (tester == NULL || currNumTesters == maxNumTesters || maxNumTesters == 0) //does this mean that testers is full?
		return -1;
		
	for (int i = 0; i < maxNumTesters; i++)
		if (testers[i] == NULL)
		{
			testers[i] = tester->clone();
			++currNumTesters;

			return i;
		}						
}

bool TesterInterface::removeTester(int pos)
{	
	if (pos >= maxNumTesters || pos < 0 || testers[pos] == NULL|| maxNumTesters == 0)
		return false;
	else 
	{		
		delete testers[pos];
		testers[pos] = NULL;
		--currNumTesters;
		
		return true; 		
	}
	
}

bool TesterInterface::evaluate(int num)
{	
	if (maxNumTesters == 0 || currNumTesters == 0) // if currNumTesters = 0 then all testers are NULL
		return false;
	
	for (int i = 0; i < maxNumTesters; i++)
	{
		if (testers[i] != NULL)
		//What if all the testers are NULL, what then?
			if (!testers[i]->evaluate(num))
				return false;	
	}
	
	return true; // because I have not yet determined what happens if all testers are NULL the value returned will be true if all of them are NULL	
}

int* TesterInterface::failedTests(int num)
{	
	if (evaluate(num) || maxNumTesters == 0 || currNumTesters == 0)
	{		
		int* failedtests = new int[0];

		return failedtests;		
	}
	else
	{
		int count = 0;
		int* alltests = new int[maxNumTesters];
		
		for (int i = 0; i < maxNumTesters; i++)
			if (testers[i] != NULL)
				if (!testers[i]->evaluate(num))
				{
					alltests[count] = i; 
					count++;
				}
		
		int* failedtests = new int[count];
		
		for (int i = 0; i < count; i++)
			failedtests[i] = alltests[i];
			
		delete [] alltests;
		alltests = NULL;

		return failedtests;		
	}	
}

int TesterInterface::numberOfFailedTests(int num)
{	
	if (evaluate(num) || maxNumTesters == 0)
		return 0;
	
	int count = 0;
	
	for (int i = 0; i < maxNumTesters; i++)
		if (testers[i] != NULL)
		{
			if (!testers[i]->evaluate(num))
			count++;
		}
	
	return count;		
}

NumberTester* TesterInterface::operator[](int pos)
{	
	if (pos >= maxNumTesters || pos < 0 || testers[pos] == NULL)
		return NULL;
	
	return testers[pos];		
}

int TesterInterface::getCurrNumTesters() const
{	
	return currNumTesters;	
}

int TesterInterface::getMaxNumTesters() const
{	
	return maxNumTesters;	
}






























