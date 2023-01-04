#include "RandomGenerator.h"
using namespace std;

RandomGenerator::RandomGenerator(int seed)
{ 
	this->seed = seed;
	srand(seed);	
}

bool RandomGenerator::randomBool()
{	
	int number;
	number = rand();

	if (number % 2 == 0) 
		return false;
	else
		return true;
}
	

